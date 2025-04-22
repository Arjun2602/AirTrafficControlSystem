#include "Flight.h"

Flight::Flight( std::string name, int maxWeight, int maxSec)
{
    this->name = name;
    this->maxWeight = maxWeight;
    this->maxSec = maxSec;
}

Flight::Flight()
:name(""),maxWeight(0),maxSec(0)
{
}

// getters
 std::string Flight::getName()
 {
     return name;
 }
 int Flight::getmaxWeight()
 {
     return maxWeight;
 }
 int Flight::getmaxSec()
 {
     return maxSec;
 }
