/*
  Student Name: William Burch
  File Name: SimRange.cpp
  Assignment number: Project 4

  object that stores the range and percentage for the simulation
 */

#include "SimRange.hpp"
/*  SimRange::getStartRange()
 *  gets the starting range
 *  Returns int - the starting range
 */
int SimRange::getStartRange() const {
    return startRange;
}
/*  SimRange::getEndRange()
 *  gets the ending range
 *  Returns int - the ending range
 */
int SimRange::getEndRange() const {
    return endRange;
}
/*  SimRange::getPercentage()
 *  gets the percentage
 *  Returns int - the percentage
 */
int SimRange::getPercentage() const {
    return percentage;
}

/*  SimRange::SimRange()
 *  creates the range object for the simulation
 *  Parameters:
 *  int startRange - the start of the range
 *  int endRange - the end of the range
 *  int percentage - the percentage of the range
 */
SimRange::SimRange(int startRange, int endRange, int percentage) {
    this->startRange = startRange;
    this->endRange = endRange;
    this->percentage = percentage;
    this->midRange = (startRange + endRange) / 2.0;
}
/*  SimRange::getMidRange()
 *  gets the value in between the beginning and end
 *  Returns double - the value halfway between the beginning and end
 */
double SimRange::getMidRange() const {
    return midRange;
}

/*  SimRange::isInRange()
 *  checks if the provided value is in range of the start or end values
 *  Parameters:
 *  double value - the value to be checked
 *  Returns bool - if it is within range or not
 */
bool SimRange::isInRange(double value) const{
    if(value >= startRange && value < endRange)
    {
        return true;
    }
    return false;
}


