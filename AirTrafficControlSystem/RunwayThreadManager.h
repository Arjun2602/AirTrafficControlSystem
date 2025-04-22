#ifndef RUNWAYTHREADMANAGER_H_INCLUDED
#define RUNWAYTHREADMANAGER_H_INCLUDED

#include <thread>
#include <chrono>

#include "Storage.h"

class RunwayThreadManager
{
public:
    void fun(int totalSeconds, int runwayNo);
};

#endif // RUNWAYTHREADMANAGER_H_INCLUDED
