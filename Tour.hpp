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
    vector<City*> tour{CITIES_IN_TOUR, nullptr};
    double fitness = 0, distance = 0;

public:
    Tour() = default;
    explicit Tour(const vector<City*>& newTour);
    City * getCity(int pos);
    int getNumberOfCities() { return tour.size(); }
    double getFitness();
    void setCity(int pos, City* city);
    double getDistance();
    string to_string();
    bool containsCity(const City* input);
    Tour& operator=(Tour other);
    friend void mySwap(Tour& first, Tour& second);
};
