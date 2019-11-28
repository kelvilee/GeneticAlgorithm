//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once

#include "Tour.hpp"
#include <set>

constexpr int POPULATION_SIZE = 32;
class Population
{
private:
    vector<Tour*> tours{POPULATION_SIZE, nullptr};
public:
    Population(int popSize, bool init);
    void saveTour(int index, Tour* tour);
    Tour* getTour(int index) { return tours.at(index); }
    Tour* getFittest();
    int populationSize() { return tours.size(); }
    ~Population();
};
