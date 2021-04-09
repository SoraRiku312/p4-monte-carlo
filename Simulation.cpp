/*
  Student Name: William Burch
  File Name: Simulation.cpp
  Assignment number: Project 4

  the simulation object and methods
 */

#include "Simulation.hpp"
#include <random>
#include <chrono>
/*  Simulation::getDays()
 *  gets the amount of days
 *  Returns int - the amount of days
 */
int Simulation::getDays() const {
    return days;
}


/*  Simulation::getNumOfCategories()
 *  gets the amount of categories/ranges
 *  Returns int - the amount of categories
 */
int Simulation::getNumOfCategories() const {
    return numOfCategories;
}


/*  Simulation::getRanges()
 *  gets the vector of ranges
 *  Returns int - the vector of ranges
 */
const std::vector<SimRange> &Simulation::getRanges() const {
    return ranges;
}


/*  Simulation::getUnits()
 *  gets the units
 *  Returns string - the units
 */
const std::string &Simulation::getUnits() const {
    return units;
}

/*  Simulation::Simulation()
 *  creates the simulation object
 *  Parameters:
 *  int days - the amount of simulated days
 *  int numOfCategories - the number of categories/ranges
 *  std::vector<SimRange> ranges - a vector of the ranges
 *  std::string units - the units simulated
 */
Simulation::Simulation(int days, int numOfCategories, std::vector<SimRange> ranges, std::string units) {

    this->days = days;
    this->numOfCategories = numOfCategories;
    this->ranges = ranges;
    this->units = units;

}
/*  Simulation::Simulation
 *  calculates the analytical model value
 *  Returns double - the value of the analytical model
 */
double Simulation::calculateAnalyticalModel()
{
    double value = 0;
    for(int i = 0; i < getNumOfCategories(); i++)
    {
        value += (ranges.at(i).getPercentage() / 100.0) * (ranges.at(i).getMidRange());
    }

    return value;
}
/*  Simulation::simulate()
 *  simulates the model with the provided values
 *  Returns double - the simulated value
 */
double Simulation::simulate()
{
    unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
    std::default_random_engine gen(seed);

    double totalValue = 0;
    double value = 0;
    int randNum;
    int randInterval = 0;
    for(int j = 0; j < days; j++)
    {
        randInterval = 0;
        std::uniform_int_distribution<int>rand2(0, 100);
        randNum = rand2(gen);

        for(int i = 0; i < getNumOfCategories(); i++)
        {
            SimRange range = ranges.at(i);
            randInterval += range.getPercentage();
            if(randNum <= randInterval){
                std::uniform_int_distribution<int>random(range.getStartRange(), range.getEndRange());
                value =  random(gen);
                totalValue += value;
                break;
            }
        }

    }

    totalValue /= days;

    return totalValue;
}