//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Population.hpp"

Population::~Population() {
    for(Tour *t : tours)
        delete t;
}

Population::Population(int popSize, bool init) {
    if(init)
        for(int i = 0; i < POPULATION_SIZE; ++i) {
            Tour *newTour = new Tour();
            newTour->generateTour();
            saveTour(i, newTour);
        }
}

void Population::saveTour(int index, Tour *tour) {
    tours.at(index) = tour;
}

Tour *Population::getFittest() {
    Tour* fittest = tours.at(0);
    for(int i = 0; i < POPULATION_SIZE; ++i)
        if(fittest->getFitness() <= getTour(i)->getFitness())
            fittest = getTour(i);
    return fittest;
}
