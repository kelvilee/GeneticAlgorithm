//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Tour.hpp"

#include <random>

Tour::Tour() {
    for(int i = 0; i < CITIES_IN_TOUR; ++i)
        tour.push_back(nullptr);
    fitness_rating = 0;
    distance = 0;
}

Tour::Tour(const vector<City*>& tour) : tour(tour) {
}

void Tour::generateTour() {
    for(int i = 0; i < CITIES_IN_TOUR; ++i)
        setCity(i, getCity(i));
}

double Tour::getDistance() {
    if(distance == 0) {
        double tourDistance = 0;
        for(int i = 0; i < CITIES_IN_TOUR; ++i) {
            City fromCity = *getCity(i);
            City destCity;
            if(i+1 < CITIES_IN_TOUR)
                destCity = *getCity(i + 1);
            else
                destCity = *getCity(0);
            tourDistance += fromCity.distanceTo(destCity);
        }
        distance = tourDistance;
    }
    return distance;
}

bool Tour::operator<(const Tour &t) const {
    return fitness_rating < t.fitness_rating;
}

bool Tour::operator==(const Tour &y) const {
    return fitness_rating == y.fitness_rating;
}

City* Tour::getCity(int pos) {
    return tour.at(pos);
}

void Tour::setCity(int pos, City* city) {
    tour.assign(pos, city);
    fitness_rating = 0;
    distance = 0;
}

double Tour::getFitness() {
    if(fitness_rating == 0)
        fitness_rating = 1 / getDistance();
    return fitness_rating;
}


