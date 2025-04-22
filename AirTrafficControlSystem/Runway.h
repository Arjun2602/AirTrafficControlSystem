#ifndef RUNWAY_H_INCLUDED
#define RUNWAY_H_INCLUDED

#include <string>

class Runway
{
private:
    int no;
    bool busy;
    int maxTime;
public:
    Runway(int no, bool busy, int maxTime);
    Runway();

    // getters
    int getNo();
    bool getBusy();
    int getMaxTime();

    // setter
    void setBusy(bool ans);
};

#endif // RUNWAY_H_INCLUDED
