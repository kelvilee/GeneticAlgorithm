//
// Created by Kelvin Lee on 2019-11-26.
//

#pragma once

#include "Population.hpp"

constexpr double MUTATION_RATE = 0.015;
constexpr int PARENT_POOL_SIZE = 5;
constexpr int NUMBER_OF_ELITES = 1;

class GeneticAlgorithm
{
public:
    Population evolvePopulation(Population pop) {
        Population* newPopulation = new Population(POPULATION_SIZE, false);

        int elitismOffset = 0;
        newPopulation->saveTour(0, pop.getFittest());

        for(int i = elitismOffset; i < newPopulation->populationSize(); i++) {
            Tour parent1 = selectCandidateTour(pop);
            Tour parent2 = selectCandidateTour(pop);
            Tour child = crossover(parent1, parent2);
            newPopulation->saveTour(i, &child);
        }
        return *newPopulation;
    }

    Tour crossover(Tour parent1, Tour parent2)
    {
        Tour* child = new Tour();
    }
};
