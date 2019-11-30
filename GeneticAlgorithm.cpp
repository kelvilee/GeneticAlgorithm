//
// Created by Kelvin Lee on 2019-11-29.
//

#include "GeneticAlgorithm.hpp"

GeneticAlgorithm::GeneticAlgorithm(const vector<City*>& inputList) : masterList(inputList){
    auto* pop = new Population(masterList);
    Tour* fittest = pop->getFittest();
    cout << fittest->to_string() << endl;
    const double base_distance = fittest->getDistance();
    double best_distance = base_distance;
    double improvement_factor = 0.75;
    int iterCount = 0;

//    while (best_distance / base_distance < improvement_factor || iterCount < ITERATIONS ) {
//        pop->selectElite(); // move elite to front
//        // perform crossover and mutation of tours;
//        vector<Tour*> crosses;
//        crosses.push_back(pop->getFittest());
//        ++iterCount;
//    }

    cout << base_distance << endl;
    cout << endl;
    cout << pop->printPopulation();

    pop->selectElite();
    cout << endl;
    cout << pop->printPopulation();

    crossover(*pop);

    // free master list and population memory
    for(City *c : masterList)
        delete c;
}

void GeneticAlgorithm::crossover(Population original) {
    // two sets of 5 random tours from original population
    set<Tour*> set1;
    set<Tour*> set2;

    // random generator to choose those 5 for each set
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> intDist(1, original.getPopSize() - 1); // don't include elite tour in crossover
    while(set1.size() < 2) {
        int randomInt1 = intDist(gen);
        set1.insert(original.getTour(randomInt1));
    }
    while(set2.size() < 2) {
        int randomInt2 = intDist(gen);
        set2.insert(original.getTour(randomInt2));
    }

    cout << endl;
    for(Tour *t :set1) {
        cout << t->to_string() << " | " << t->getFitness() << endl;
    }
    for(Tour *t :set2)
        cout << t->to_string() << " | " << t->getFitness() << endl;


//    for(Tour* t: set1)
//        cout << t->to_string();
}

//Tour* getFittestParent(set<Tour*> tours) {
//    Tour* fittest = tours[0];
//    for(int i = 0; i < tours.size(); ++i)
//        if(fittest->getFitness() <= getTour(i)->getFitness())
//            fittest = getTour(i);
//    return fittest;
//}
