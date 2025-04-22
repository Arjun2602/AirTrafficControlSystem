#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED

#include <iostream>
#include <string>
#include <iomanip>
#include <thread>
#include <chrono>
#include <queue>

#include "Storage.h"
#include "RunwayThreadManager.h"

class System
{
public:
    void alloteRunway(std::string name, int weight, int totalSeconds, bool flag);
    int computeSecond(std::string name, int weight);
    void takeOff();
    void runAThread(int totalSeconds, int runwayNo);

    void landing();
};

#endif // SYSTEM_H_INCLUDED
