//
// Created by Kelvin Lee on 2019-11-29.
//

#ifndef GENETICALGORITHM_GENETICALGORITHM_HPP
#define GENETICALGORITHM_GENETICALGORITHM_HPP

#include "Population.hpp"
#include <set>
constexpr int ITERATIONS = 1000;
class GeneticAlgorithm
{
private:
    vector<City*> masterList;
public:
    GeneticAlgorithm(const vector<City*>& inputList);
    void crossover(Population original);
};
#endif //GENETICALGORITHM_GENETICALGORITHM_HPP
