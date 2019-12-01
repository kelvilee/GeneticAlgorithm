#include <iostream>
#include "GeneticAlgorithm.hpp"

int main() {
    // group of cities (master list)
    vector<City*> master_list;
    master_list.push_back(new City("Vancouver", 67, 234));
    master_list.push_back(new City("Burnaby", 184, 211));
    master_list.push_back(new City("Surrey", 83, 182));
    master_list.push_back(new City("New West", 405, 12));
    master_list.push_back(new City("Port Coquitlam", 803, 302));
    master_list.push_back(new City("Langley", 600, 650));
    master_list.push_back(new City("Port Moody", 950, 32));
    master_list.push_back(new City("Downtown", 123, 760));
    master_list.push_back(new City("Jasper", 340, 230));
    master_list.push_back(new City("Mission", 504, 784));

    // apply genetic algorthm for tsp
    GeneticAlgorithm ga{master_list};

    // free pointers in master list
    for(City* c: master_list) {
        delete c;
    }
    return 0;
}