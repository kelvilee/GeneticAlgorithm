//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once

#include <string>
#include <iostream>
#include <cmath>

using namespace std;

struct City
{
    string name;
    int x = 0, y = 0;
    City() = default;
    City(string name, int x, int y) : name(name), x(x), y(y) { }
    double distanceTo(const City& dest);
    string to_string();
    bool operator == (const City& m) const;
    City& operator=(City other);
    friend void mySwap(City& first, City& second);
};
