//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Tour.hpp"

#include <random>

void Tour::generateTour() {
    shuffle(tour.begin(), tour.end(), std::mt19937(std::random_device()()));
}

double Tour::getDistance() {
    if (distance == 0) {
        double tourDistance = 0;
        for (int i = 0; i < tour.size(); ++i) {
            City fromCity = getCity(i);
            City destCity;
            if (i + 1 < tour.size())
                destCity = getCity(i + 1);
            else
                destCity = getCity(0);
            tourDistance += fromCity.distanceTo(destCity);
        }
        distance = tourDistance;
    }
    return distance;
}

City Tour::getCity(int pos) {
    return *tour.at(pos);
}

void Tour::setCity(int pos, City* city) {
    tour.assign(pos, city);
    fitness = 0;
    distance = 0;
}

double Tour::getFitness() {
    fitness = 1.0 / getDistance();
    fitness *= 10000;
    return fitness;
}

string Tour::to_string() {
    string result = "| ";
    for (int i = 0; i < tour.size(); ++i)
        result += getCity(i).to_string() + " | ";
    return result;
}

Tour::Tour(const vector<City *>& newTour) : tour(newTour) {
    shuffle(tour.begin(), tour.end(), std::mt19937(std::random_device()()));
    distance = getDistance();
    fitness = getFitness();
}

Tour &Tour::operator=(Tour other) {
    mySwap(*this, other);
    return *this;
}

void mySwap(Tour &first, Tour &second) {
    first.tour.swap(second.tour);
    using std::swap;
    swap(first.fitness, second.fitness);
    swap(first.distance, second.fitness);
}
