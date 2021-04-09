/*
  Student Name: William Burch
  File Name: SimRange.cpp
  Assignment number: Project 4

  object that stores the range and percentage for the simulation
 */

#ifndef PROJECT4_SIMRANGE_HPP
#define PROJECT4_SIMRANGE_HPP


class SimRange {
private:
    int startRange;
    double midRange;
    int endRange;
    int percentage;

public:

    SimRange(int startRange, int endRange, int percentage);

    int getStartRange() const;

    int getEndRange() const;

    int getPercentage() const;

    double getMidRange() const;

    bool isInRange(double value) const;
};


#endif //PROJECT4_SIMRANGE_HPP
