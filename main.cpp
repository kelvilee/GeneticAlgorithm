#include <iostream>
#include "Tour.hpp"
#include "Population.hpp"

int main() {
//    vector<City> master_list;
//    master_list.emplace_back("Vancouver", 0, 0);
//    master_list.emplace_back("Surrey", 222, 495);
//    master_list.emplace_back("Burnaby", 140, 497);
//    master_list.emplace_back("Richmond", 373, 655);
    TourManager tourManager;
    City* city1 = new City("Van", 60, 200);
    tourManager.addCity(city1);
    City* city2 = new City("Bby", 180, 200);
    tourManager.addCity(city2);
    City* city3 = new City("Surrey", 80, 180);
    tourManager.addCity(city3);

    Population* population = new Population(32, true);
    cout << "Initial distance: " << population->getFittest()->getDistance();
    return 0;
}