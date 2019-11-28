//
// Created by Kelvin Lee on 2019-11-26.
//

#pragma once

#include "City.hpp"
#include <vector>

class TourManager
{
private:
    vector<City*> destCities;
public:
    void addCity(City* city) { destCities.push_back(city); };
    City getCity(int index) { return *destCities[index]; };
    int numOfCities() { return destCities.size(); }
};
