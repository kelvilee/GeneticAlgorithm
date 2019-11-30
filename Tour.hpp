//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once
#include <vector>
#include <random>

#include "City.hpp"

constexpr int CITIES_IN_TOUR = 32;

using namespace std;
class Tour
{
private:
    vector<City*> tour; //list of cities
    double fitness = 0;
    double distance = 0;

public:
    Tour(const vector<City*>& newTour);
    void generateTour();
    City getCity(int pos);
    double getFitness();
    void setCity(int pos, City* city);
    double getDistance();
    string to_string();
    Tour& operator=(Tour other);
    friend void mySwap(Tour& first, Tour& second);
};
