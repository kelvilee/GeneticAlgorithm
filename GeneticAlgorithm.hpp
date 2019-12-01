//
// Created by Kelvin Lee on 2019-11-29.
//

#pragma once

#include "Population.hpp"

constexpr int MAP_BOUNDARY = 1000;
constexpr int ITERATIONS = 1000;
constexpr int PARENT_POOL_SIZE = 5;
constexpr double MUTATION_RATE = 0.15;
constexpr double IMPROVEMENT_FACTOR = 0.25;

class GeneticAlgorithm
{
private:
    vector<City*> masterList{CITIES_IN_TOUR, nullptr};
public:
    explicit GeneticAlgorithm(const vector<City*>& inputList);
    static Tour* crossover(Population original);
    static void mutation(Population original);
};
