//
// Created by Kelvin Lee on 2019-11-29.
//

#include "GeneticAlgorithm.hpp"

/**
 * Runs a genetic algorithm to find an improved path to the travelling salesman problem
 * @param inputList list of cities to perform TSP on
 */
GeneticAlgorithm::GeneticAlgorithm(const vector<City*>& inputList) : masterList(inputList){
    // CREATE CITIES
    auto *pop = new Population(masterList);

    // EVALUATE FITNESS
    Tour* fittest = pop->getFittest();
    const double base_distance = fittest->getDistance();
    double best_distance = base_distance;
    int iterCount = 0;
    bool improvement = false;

    // Run the genetic algorithm
    while(1 - (best_distance / base_distance) < IMPROVEMENT_FACTOR && iterCount < ITERATIONS) {
        // MOVE ELITE TO FRONT
        pop->selectElite();
        // PERFORM CROSSOVER
        for(int i = 1; i < POPULATION_SIZE; ++i) {
            pop->saveTour(i, crossover(*pop));
        }
        // PERFORM MUTATION
        mutation(*pop);
        // EVALUATE FITNESS
        Tour* newFittest = pop->getFittest();
        double iterDistance = newFittest->getDistance();
        //if distance is improved over best distance, update best distance and set improvement
        if(iterDistance < best_distance) {
            best_distance = iterDistance;
            improvement = true;
        } else {
            improvement = false;
        }
        // Iteration results
        cout << "Iteration:\t\t" << ++iterCount << endl;
        cout << "Distance:\t\t" << iterDistance << endl;
        cout << "Best Distance:\t" << best_distance << endl;
        cout << "Improved?:\t\t" << boolalpha << improvement << endl;
        cout << "Improvement Over Base:\t" << (1 - (iterDistance / base_distance)) * 100 << "%" << endl;
        cout << endl;
    }
    // Final report
    cout << "Number of iterations:\t" << iterCount << endl;
    cout << "Base distance:\t" << base_distance << endl;
    cout << "Best distance:\t" << best_distance << endl;
    cout << "Achieved Improvement Factor?:\t" << boolalpha << (iterCount != ITERATIONS) << endl;
    cout << "Base Route:\t" << fittest->to_string() << endl;
    cout << "Best Route:\t" << pop->getFittest()->to_string() << endl;
}

/**
 * Gets fittest parent in a subset of tours
 * @param list subset of tours
 * @return fittest parent in subset
 */
Tour* getFittestParent(vector<Tour*> list) {
    Tour* fittest = list[0];
    for(int i = 1; i < list.size(); ++i) {
        if (fittest->getFitness() <= list[i]->getFitness())
            fittest = list[i];
    }
    return fittest;
}

/**
 * Creates a two sets of Tours from the Population of Tours passed in as a parameter,
 * finds the fittest of each set and creates a child from the cities in both parents.
 * Returns the new child Tour as new Tour.
 * @param Population to be crossed over
 * @return merged Tour pointer
 */
Tour* GeneticAlgorithm::crossover(Population original) {
    // two sets of 5 random tours from original population
    vector<Tour*> set1;
    vector<Tour*> set2;

    // random generator to choose those 5 for each set
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> intDist(1, original.getPopSize() - 1); // don't include elite tour in crossover

    // each tour in set is unique
    while(set1.size() < PARENT_POOL_SIZE) {
        int randomInt1 = intDist(gen);
        set1.push_back(original.getTour(randomInt1));
    }
    while(set2.size() < PARENT_POOL_SIZE) {
        int randomInt2 = intDist(gen);
        set2.push_back(original.getTour(randomInt2));
    }

    // pointers to two fittest parents in sets
    Tour* parent1 = getFittestParent(set1);
    Tour* parent2 = getFittestParent(set2);
    Tour* child = new Tour();

    uniform_int_distribution<> crossingDist(0, CITIES_IN_TOUR - 1);
    int randomIndex = crossingDist(gen);

    // copies everything up to randomIndex from parent 1
    for(int i = 0; i <= randomIndex; ++i) {
        child->setCity(i, parent1->getCity(i));
    }
    // fills rest of child tour with parent 2
    for(int i = randomIndex + 1; i < CITIES_IN_TOUR; ++i) {
        for(int j = 0; j < CITIES_IN_TOUR; ++j) {
            if(!child->containsCity(parent2->getCity(j))) { // if child doesn't have city yet, add it
                child->setCity(i, parent2->getCity(j));
                break;
            }
        }
    }

    return child;
}

/**
 * Given a population of tours select a select few tours for a random chance to mutate.
 * Mutation swaps adjacent cities and can happen for every single city in a mutated tour
 * @param original population to mutate
 */
void GeneticAlgorithm::mutation(Population original) {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> mutateDist(1, original.getPopSize() - 1); // don't include elite tour in possible mutation
    uniform_real_distribution<> toursToMutate(0.25, 0.35); // choose 25-35% of the population to mutate
    uniform_real_distribution<> randomMutationValue(0, 1); // mutate tour if random value is under 0.15
    uniform_int_distribution<> leftOrRight(0, 1); // choose to mutate with adjacent cities

    int numOfMutations = (int)(original.getPopSize() * toursToMutate(gen));

    for(int i = 0; i < numOfMutations; ++i) {
        Tour* toMutate = original.getTour(mutateDist(gen)); // grab a random tour from population to mutate
        int numOfCities = toMutate->getNumberOfCities();
        for(int j = 0; j < numOfCities; ++j) { //iterate over all cities from tour
            if (randomMutationValue(gen) < MUTATION_RATE) {
                // swap with randomly chosen adjacent city
                City *tmp = toMutate->getCity(j);
                if(j == 0) { // must swap with second element
                    toMutate->setCity(j, toMutate->getCity(j + 1));
                    toMutate->setCity(j + 1, tmp);
                } else if(j == numOfCities - 1) { // must swap with the second last element
                    toMutate->setCity(j, toMutate->getCity(j - 1));
                    toMutate->setCity(j - 1, tmp);
                } else {
                    if(0 == leftOrRight(gen)) {
                        toMutate->setCity(j, toMutate->getCity(j + 1));
                        toMutate->setCity(j + 1, tmp);
                    } else {
                        toMutate->setCity(j, toMutate->getCity(j - 1));
                        toMutate->setCity(j - 1, tmp);
                    }
                }
            }
        }
    }
}
