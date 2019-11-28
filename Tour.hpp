//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once
#include <vector>
#include <random>
#include "TourManager.hpp"
constexpr int CITIES_IN_TOUR = 32;

using namespace std;
class Tour
{
private:
    vector<City*> tour;
    double fitness_rating;
    double distance;

public:
    Tour();
    ~Tour() { };
    Tour(const vector<City*>& master_list);
    void generateTour();
    City* getCity(int pos);
    double getFitness();
    void setCity(int pos, City* city);
    bool operator < (const Tour& t) const;
    bool operator == (const Tour& t) const;
    double getDistance();
    string to_string() {
        string result = "|";
        for(int i = 0; i < CITIES_IN_TOUR; ++i)
            result += getCity(i)->to_string() + "|";
        return result;
    }
};
