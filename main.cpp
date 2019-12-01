#include <iostream>
#include "GeneticAlgorithm.hpp"

int main() {
    // group of cities (master list)
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> randomInt(0, MAP_BOUNDARY);
    vector<City*> master_list;
    for(int i = 1; i <= CITIES_IN_TOUR; ++i) {
       master_list.push_back(new City(std::to_string(i), randomInt(gen), randomInt(gen)));
    }

    // apply genetic algorithm for TSP
    GeneticAlgorithm ga{master_list};

    // free memory
    for(City* c: master_list) {
        delete c;
    }
    return 0;
}