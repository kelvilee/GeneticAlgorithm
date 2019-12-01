//
// Created by Kelvin Lee on 2019-11-25.
//

#include "City.hpp"

double City::distanceTo(const City& dest) {
    double xDis = abs(x - dest.x);
    double yDis = abs(y - dest.y);
    double dist = sqrt((xDis * xDis) + (yDis * yDis));
    return dist;
}

string City::to_string() {
    string result = "City: " + name + " Position: " + std::to_string(x) + ", " + std::to_string(y);
    return result;
}

bool City::operator==(const City& c) const {
    return name == c.name;
}
