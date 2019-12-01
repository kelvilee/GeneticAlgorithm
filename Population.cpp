//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Population.hpp"

Population::Population(vector<City*> &seed) {
    for(int i = 0; i < POPULATION_SIZE; ++i) {
        Tour* newTour = new Tour(seed); // creating shuffles
        tours.push_back(newTour);
    }
}

void Population::saveTour(int index, Tour* tour) {
    tours.at(index) = tour;
}

Tour* Population::getFittest() {
    Tour* fittest = tours.at(0);
    for(int i = 0; i < tours.size(); ++i)
        if(fittest->getFitness() <= getTour(i)->getFitness())
            fittest = getTour(i);
    return fittest;
}

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

