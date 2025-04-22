#ifndef STORAGE_H_INCLUDED
#define STORAGE_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>

#include "Runway.h"
#include "Flight.h"

class Storage
{
public:
    static std::map<int, Runway> runwayList;
    static std::unordered_map<std::string, Flight> flightMap;
};

#endif // STORAGE_H_INCLUDED
