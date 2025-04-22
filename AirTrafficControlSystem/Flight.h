#ifndef FLIGHT_H_INCLUDED
#define FLIGHT_H_INCLUDED

#include <string>

class Flight
{
private:
    std::string name;
    int maxWeight;
    int maxSec;
public:
    Flight( std::string name, int maxWeight, int maxSec);
    Flight();

    // getters
     std::string getName();
     int getmaxWeight();
     int getmaxSec();
};

#endif // FLIGHT_H_INCLUDED
