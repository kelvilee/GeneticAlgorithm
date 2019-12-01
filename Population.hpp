//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once

#include "Tour.hpp"
#include <algorithm>
#include <random>

constexpr int POPULATION_SIZE = 10;
constexpr int PARENT_POOL_SIZE = 5;

class Population
{
private:
    vector<Tour*> tours;
public:
    explicit Population(vector<City*>& seed);
    void saveTour(int index, Tour* tour);
    void selectElite();
    int getPopSize() { return tours.size(); }
    Tour* getTour(int index) { return tours.at(index); }
    Tour* getFittest();
};
