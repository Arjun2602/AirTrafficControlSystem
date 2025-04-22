#include "Runway.h"

Runway::Runway(int no, bool busy, int maxTime)
{
    this->no = no;
    this->busy = busy;
    this->maxTime = maxTime;
}

Runway::Runway()
:no(0),busy(false),maxTime(0)
{
}

// getters
int Runway::getNo()
{
    return no;
}
bool Runway::getBusy()
{
    return busy;
}
int Runway::getMaxTime()
{
    return maxTime;
}

// setters
void Runway::setBusy(bool ans)
{
    this->busy = ans;
}
