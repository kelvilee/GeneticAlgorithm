//
// Created by Kelvin Lee on 2019-11-25.
//

#pragma once
#include <string>
#include <iostream>
#include <cmath>

//constexpr int MAP_BOUNDARY = 1000;
using namespace std;

struct City
{
    string name;
    int x, y;
    City() = default;
    City(string name, int x, int y) : name(name), x(x), y(y) { }
    double distanceTo(const City& dest);
    string to_string();
};
