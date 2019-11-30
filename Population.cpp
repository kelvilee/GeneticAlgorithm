//
// Created by Kelvin Lee on 2019-11-25.
//

#include "Population.hpp"

Population::Population(vector<City*> &seed) {
    for(int i = 0; i < 4; ++i) {
        Tour* newTour = new Tour(seed); // creating shuffles
        tours.push_back(newTour);
    }
//    sort(tours.begin(), tours.end(), tour_compare);
}

Population::~Population() {
    for(Tour *t : tours)
        delete t;
}

void Population::saveTour(int index, Tour* tour) {
    tours.at(index) = tour;
}

Tour* Population::getFittest() {
    Tour* fittest = tours.at(0);
    for(int i = 0; i < tours.size(); ++i)
        if(fittest->getFitness() <= getTour(i)->getFitness())
            fittest = getTour(i);
    return fittest;
}

string Population::printPopulation() {
    string result = "";
    for(Tour *t : tours) {
        result += t->to_string() + std::to_string(t->getDistance()) + " - "+ std::to_string(t->getFitness()) + "\n";
    }
    return result;
}

/**
 * Custom comparator to sort tour fitness
 * @param lhs first tour
 * @param rhs second tour
 * @return bool
 */
bool tour_compare(Tour* lhs, Tour* rhs)
{
    return lhs->getFitness() > rhs->getFitness();
}



void Population::selectElite() {
    Tour* fittest = tours.at(0);
    int index = 0;
    for(int i = 0; i < tours.size(); ++i)
        if(fittest->getFitness() <= getTour(i)->getFitness()) {
            fittest = getTour(i);
            index = i;
        }
    std::swap(tours[0], tours[index]);
}

//void Population::crossover() {
//    vector<Tour*> set1;
//    vector<Tour*> set2;
//    random_device rd;
//    mt19937 gen(rd());
//    uniform_int_distribution<> intDist(1, tours.size() - 1);
//    for(int i = 0; i < 2; ++i) {
//        int randomInt1 = intDist(gen);
//        int randomInt2 = intDist(gen);
//        set1.push_back(tours[randomInt1]);
//        set2.push_back(tours[randomInt2]);
//    }
//
//    for(Tour* t: set1)
//        cout << t->to_string();
//}
