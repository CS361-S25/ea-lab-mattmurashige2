#include <iostream>
#include <string>
#include "Empirical/include/emp/math/Random.hpp"

class Organism {
    public:
    double behavior;
    //a. First you’ll need an Organism class that has an instance variable double behavior and a constructor that takes a double and sets the instance variable.
    Organism(double b) : behavior(b) {}

    //Create a reproduce function in your Organism class that returns a pointer to an Organism and takes no arguments currently.
    //This function should create a new Organism with a behavior that is a random number between 0 and 1.
    //Dont't actually need to pass parent!!!
    Organism* reproduce(emp::Random& random) { //reference the random variable's memory address to get the right sequence of numbers!
        Organism* offspring = new Organism(behavior);
        offspring->mutate(random);
        return offspring;
    }

    void mutate(emp::Random& random) { //reference the random variable's memory address to get the right sequence of numbers!
        behavior += random.GetRandNormal(0.0, 0.02);
    }
};

int main() {

    //Exercise 1
    emp::Random random = *new emp::Random(2);
    emp::vector<Organism> population;
    for (int i = 0; i < 100; i++) {
        population.push_back(*new Organism(0.5)); //Create a new organism pointer, then you dereference that organism pointer
        population[i].mutate(random);
    }

    //Print out the behavior of an organism in your population to see that everything is working. Make sure your code compiles and runs. You may see some warnings which you can ignore for now.
    std::cout << "Behavior of first organism: " << population[0].behavior << std::endl; //Can do this because we set organism class to public! Would be better for it to be a getter (more formal?)
  
    //Exercise 2
    //Verify that your reproduction function works by calling it on an Organism in your population in main and printing the parent and offspring’s addresses and behaviors. Compile and run your code at this point.
    Organism parent(0.5); //Create a parent organism
    Organism* offspring = parent.reproduce(random); //Offspring organism uses reproduce function which returns a new organism whose pointer is the same as the parent?
    std::cout << "Parent address: " << &parent << ", Parent behavior: " << parent.behavior << std::endl;
    std::cout << "Offspring address: " << offspring << ", Offspring behavior: " << offspring->behavior << std::endl;

    //Exercise 3

    for(int i = 0; i < 100; i++) {
        Organism& curMax = population[0]; //Make a reference variable because you are going to call a method on curMax!
        for(Organism j : population) {
            if (j.behavior > curMax.behavior) {
                curMax = j;
            }
        }
        Organism* new_org = curMax.reproduce(random);
        int overwrite = random.GetUInt(0, 100);
        population[overwrite] = *new_org;
    }

    std::cout << "Population size:" << population.size() << std::endl;
    Organism& curMax = population[0];
    for(Organism j : population) {
        if (j.behavior > curMax.behavior) {
            curMax = j;
        }
    }
    std::cout << "Max behavior: " << curMax.behavior << std::endl;

}