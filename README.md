
# Traveling Salesperson Problem
Object-oriented C++ implementation of the travelling salesperson problem using a genetic algorithm  for COMP3522 Object Oriented Programming 2 at the British Columbia Institute of Technology

## Background
Given a list of cities and the distances between each pair of cities, what is the shortest possible route that visits each city and returns to the origin city?

Suppose we have an unordered list of cities to visit. We want to sort and visit the cities in a sequence that minimizes the distance travelled. With a small number of cities this is trivial, but with a large number of cities this can take a very long time. A genetic algorithm is one approach that makes this easier.

A genetic algorithm is an algorithm that draws inspiration from theories of natural selection. That is, we start with a population of sample candidates, evaluate their fitness, perform some sort of cross-over and mutation, and continue until we have a solution that most closely meets our needs or meets our termination criteria.

## Usage
Compile:
`g++ -std=c++14 main.cpp GeneticAlgorithm.cpp Population.cpp Tour.cpp City.cpp -o main`
Execute:
`./main`

### Sample Output
```
Iteration:		155
Distance:		11730.4
Best Distance:	11730.4
Improved?:		false
Improvement Over Base:	18.8111%
```
**Iteration**: current iteration number
**Distance**: current distance for the route
**Best Distance**: best distance achieved so far
**Improved?**: true if improvement over last iteration
**Improvement Over Base**: percentage improvement over initial route
### Final Output
```
Number of iterations:	325
Base distance:	14448.2
Best distance:	10763.8
Achieved Improvement Factor?:	true
Base Route:	| City: 18 Position: 918, 315 | City: 13 Position: 718, 451 | City: 16 Position: 805, 465 | City: 20 Position: 765, 86 | City: 10 Position: 721, 64 | City: 26 Position: 603, 89 | City: 1 Position: 592, 776 | City: 7 Position: 208, 514 | City: 32 Position: 372, 746 | City: 27 Position: 990, 931 | City: 9 Position: 793, 656 | City: 17 Position: 992, 952 | City: 12 Position: 273, 401 | City: 5 Position: 221, 451 | City: 30 Position: 131, 58 | City: 3 Position: 123, 135 | City: 25 Position: 572, 973 | City: 28 Position: 915, 284 | City: 2 Position: 632, 834 | City: 21 Position: 32, 428 | City: 4 Position: 463, 274 | City: 8 Position: 688, 559 | City: 22 Position: 557, 153 | City: 29 Position: 242, 196 | City: 11 Position: 183, 939 | City: 24 Position: 347, 29 | City: 6 Position: 105, 715 | City: 14 Position: 422, 947 | City: 19 Position: 780, 792 | City: 15 Position: 131, 650 | City: 23 Position: 450, 482 | City: 31 Position: 810, 335 |
Best Route:	| City: 24 Position: 347, 29 | City: 16 Position: 805, 465 | City: 9 Position: 793, 656 | City: 27 Position: 990, 931 | City: 17 Position: 992, 952 | City: 19 Position: 780, 792 | City: 2 Position: 632, 834 | City: 32 Position: 372, 746 | City: 6 Position: 105, 715 | City: 15 Position: 131, 650 | City: 21 Position: 32, 428 | City: 5 Position: 221, 451 | City: 10 Position: 721, 64 | City: 31 Position: 810, 335 | City: 18 Position: 918, 315 | City: 11 Position: 183, 939 | City: 3 Position: 123, 135 | City: 22 Position: 557, 153 | City: 13 Position: 718, 451 | City: 14 Position: 422, 947 | City: 25 Position: 572, 973 | City: 1 Position: 592, 776 | City: 23 Position: 450, 482 | City: 7 Position: 208, 514 | City: 29 Position: 242, 196 | City: 30 Position: 131, 58 | City: 20 Position: 765, 86 | City: 28 Position: 915, 284 | City: 8 Position: 688, 559 | City: 4 Position: 463, 274 | City: 12 Position: 273, 401 | City: 26 Position: 603, 89 |
```
**Number of iterations**: how many times the algorithm ran before reaching improvement factor (maximum 1000 iterations if it doesn't reach improvement factor)
**Base distance**: initial distance given the base route
**Best distance**: final distance after applying the genetic algorithm
**Achieved Improvement Factor?**: true if reached improvement factor (default is 25%)
**Base Route**: initial route (randomly generated for each run)
**Best Route**: final route after applying the genetic algorithm
