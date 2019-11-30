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

    GeneticAlgorithm ga{master_list};

    return 0;
}