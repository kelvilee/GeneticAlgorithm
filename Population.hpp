//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once

#include "Tour.hpp"
#include <algorithm>
#include <random>

constexpr int POPULATION_SIZE = 32;
constexpr int PARENT_POOL_SIZE = 5;
//constexpr int
class Population
{
private:
    vector<Tour*> tours;
public:
    Population(vector<City*>& seed);
    void saveTour(int index, Tour* tour);
    void selectElite();
//    void crossover();
    int getPopSize() { return tours.size(); }
    Tour* getTour(int index) { return tours.at(index); }
    Tour* getFittest();
    string printPopulation();
    ~Population();
};
