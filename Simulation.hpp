/*
  Student Name: William Burch
  File Name: Simulation.hpp
  Assignment number: Project 4

  the simulation object and methods
 */

#ifndef PROJECT4_SIMULATION_HPP
#define PROJECT4_SIMULATION_HPP
#include "SimRange.hpp"
#include <iostream>
#include <vector>
#include <string>

class Simulation {
private:
    int days;
    int numOfCategories;
    std::vector<SimRange> ranges;
    std::string units;
public:
    Simulation(int days, int numOfCategories, std::vector<SimRange> ranges, std::string units);

    int getDays() const;

    int getNumOfCategories() const;

    const std::vector<SimRange> &getRanges() const;

    const std::string &getUnits() const;

    double calculateAnalyticalModel();

    double simulate();
};


#endif //PROJECT4_SIMULATION_HPP
