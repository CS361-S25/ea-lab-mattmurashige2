#include <iostream>
#include <string>
#include "Empirical/include/emp/math/Random.hpp"

class Organism {
    public:
    double behavior;
    //a. First you’ll need an Organism class that has an instance variable double behavior and a constructor that takes a double and sets the instance variable.
    Organism(double b) : behavior(b) {}
};

int main() {

    emp::vector<Organism> population;
    for (int i = 0; i < 100; i++) {
        population.push_back(*new Organism(0.5));
    }
    //Print out the behavior of an organism in your population to see that everything is working. Make sure your code compiles and runs. You may see some warnings which you can ignore for now.
    std::cout << "Behavior of first organism: " << population[0].behavior << std::endl;
}