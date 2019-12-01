//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Tour.hpp"

/**
 * Constructor to create a random tour of a given vector of City objects
 * @param newTour cities to create tour from
 */
Tour::Tour(const vector<City *>& newTour) : tour(newTour) {
    shuffle(tour.begin(), tour.end(), std::mt19937(std::random_device()()));
    distance = getDistance();
    fitness = getFitness();
}

/**
 * Gets the distance of the current tour
 * @return distance as double
 */
double Tour::getDistance() {
    if (distance == 0) {
        double tourDistance = 0;
        for (int i = 0; i < (int)tour.size(); ++i) {
            City* fromCity = getCity(i);
            City* destCity;
            if (i + 1 < tour.size())
                destCity = getCity(i + 1);
            else
                destCity = getCity(0);
            tourDistance += fromCity->distanceTo(*destCity);
        }
        distance = tourDistance;
    }
    return distance;
}

/**
 * Returns city at a given position
 * @param pos index position of tour
 * @return pointer to the City
 */
City * Tour::getCity(int pos) {
    return tour.at(pos);
}

/**
 * Sets city at a given position
 * @param pos index position of tour
 * @param city City to be set
 */
void Tour::setCity(int pos, City* city) {
    tour[pos] = city;
    fitness = 0;
    distance = 0;
}

/**
 * Gets the current fitness of the tour
 * @return fitness as double
 */
double Tour::getFitness() {
    fitness = 1.0 / getDistance();
    fitness *= 10000;
    return fitness;
}

/**
 * Prints out the Tour
 * @return tour as a string
 */
string Tour::to_string() {
    string result = "| ";
    for (int i = 0; i < (int)tour.size(); ++i)
        result += getCity(i)->to_string() + " | ";
    return result;
}

/**
 * Checks if the tour contains a specific city
 * @param input City to check
 * @return boolean whether tour includes city
 */
bool Tour::containsCity(const City* input) {
    for(City* c: tour)
        if(c != nullptr)
            if(c->name == input->name)
                return true;
    return false;
}

/**
 * Overloaded = operator
 * @param other
 * @return tour
 */
Tour &Tour::operator=(Tour other) {
    mySwap(*this, other);
    return *this;
}

/**
 * Swap function
 * @param first
 * @param second
 */
void mySwap(Tour& first, Tour& second) {
    using std::swap;
    swap(first.tour, second.tour);
    swap(first.distance, second.distance);
    swap(first.fitness, second.fitness);
}

