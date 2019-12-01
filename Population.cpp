//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Population.hpp"

/**
 * Constructor to build a population given a seed tour
 * @param seed tour to create population from
 */
Population::Population(vector<City*> &seed) {
    for(int i = 0; i < POPULATION_SIZE; ++i) {
        Tour* newTour = new Tour(seed); // creating shuffles
        tours.push_back(newTour);
    }
}

/**
 * Save tour in a population given a specific position and tour
 * @param index position of save
 * @param tour tour to set
 */
void Population::saveTour(int index, Tour* tour) {
    tours.at(index) = tour;
}

/**
 * Gets the fittest tour in the population
 * @return pointer to fittest tour
 */
Tour* Population::getFittest() {
    Tour* fittest = tours.at(0);
    for(int i = 0; i < tours.size(); ++i)
        if(fittest->getFitness() <= getTour(i)->getFitness())
            fittest = getTour(i);
    return fittest;
}

/**
 * Selects elite tour and moves to front of population
 */
void Population::selectElite() {
    Tour* fittest = tours.at(0);
    int index = 0;
    for(int i = 0; i < tours.size(); ++i)
        if(fittest->getFitness() <= getTour(i)->getFitness()) {
            fittest = getTour(i);
            index = i;
        }
    std::swap(tours[0], tours[index]);
}
