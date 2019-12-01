//
// Created by Kelvin Lee on 2019-11-25.
//

#include "City.hpp"

/**
 * Calculates distance from source city to destination city
 * @param dest city to travel to
 * @return distance as double
 */
double City::distanceTo(const City& dest) {
    double xDis = abs(x - dest.x);
    double yDis = abs(y - dest.y);
    double dist = sqrt((xDis * xDis) + (yDis * yDis));
    return dist;
}

/**
 * Prints out city
 * @return city as string
 */
string City::to_string() {
    string result = "City: " + name + " Position: " + std::to_string(x) + ", " + std::to_string(y);
    return result;
}

/**
 * Comparison operator to see if two cities are equal
 * @param c city to compare
 * @return boolean if cities are equal
 */
bool City::operator==(const City& c) const {
    return name == c.name;
}

/**
 * Overloaded = operator
 * @param other
 * @return city
 */
City &City::operator=(City other) {
    mySwap(*this, other);
    return *this;
}

/**
 * Swap function
 * @param first
 * @param second
 */
void mySwap(City &first, City &second) {
    using std::swap;
    swap(first.name, second.name);
    swap(first.x, second.x);
    swap(first.y, second.y);
}
