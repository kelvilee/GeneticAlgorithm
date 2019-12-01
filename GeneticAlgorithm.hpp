//
// Created by Kelvin Lee on 2019-11-29.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Population.hpp"

constexpr int ITERATIONS = 1000;
constexpr double MUTATION_RATE = 0.15;
constexpr double IMPROVEMENT_FACTOR = 0.25;

class GeneticAlgorithm
{
private:
    vector<City*> masterList;
public:
    explicit GeneticAlgorithm(const vector<City*>& inputList);
    Tour* crossover(Population original);
    void mutation(Population original);
};
#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
