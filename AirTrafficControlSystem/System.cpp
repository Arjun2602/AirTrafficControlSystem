#include "System.h"
int System::computeSecond(std::string name, int weight)
{
    int maxWeight;
    int percentage = 0;
    int fullTime;
    int givenTime;

    maxWeight = Storage::flightMap[name].getmaxWeight();
    percentage = (weight*100) / maxWeight;

    //std::cout << "Maxweight : " << maxWeight << std::endl;
    //std::cout << "Percentage: " << percentage << std::endl;
    fullTime = Storage::flightMap[name].getmaxSec();
    if(percentage >= 75)
    {
        // full time
        givenTime = fullTime;
    }else if(percentage >= 50 && percentage < 75)
    {
        // fulltime-(10% of full time)
        givenTime = fullTime - ((fullTime*10)/100);
    }else if(percentage < 50)
    {
        // fulltime-(20% of full time)
        givenTime = fullTime - ((fullTime*20)/100);
    }

    return givenTime + 10;
}

void System::runAThread(int totalSeconds, int runwayNo)
{
    RunwayThreadManager obj;
    std::thread t1(&RunwayThreadManager::fun, &obj,totalSeconds, runwayNo);
    if(t1.joinable())
    {
        t1.detach();
    }
}
// allote runway
void System::alloteRunway(std::string name, int weight, int totalSeconds, bool kodi)
{
    std::string process;
    if(kodi)process = "Takeoff";
    else process = "Landing";
    int flag = 0;
    for(auto a : Storage::runwayList)
    {
        Runway& run = a.second;
        if(totalSeconds <= run.getMaxTime() && run.getBusy() == false)
        {
            runAThread(totalSeconds, run.getNo());
            flag = 1;
            std::cout <<process << " approved for " << name << " with " << weight << " tonnes of weight in Runway " << run.getNo() << std::endl;
            std::cout << "Touch down will happen in 15secs" << std::endl;
            std::cout << "The plane will stop after " << totalSeconds << " sec" << std::endl;
            std::cout << "Runway " << run.getNo() << " will be ready for next request in " << totalSeconds << " sec" << std::endl;
            /*
            landig app for airbus with weight in r1
            Touch down will happen in 15 sec // not cal for runway
            the plane will stop after  35 sec 0f touch down
            r1 will be ready for next req in 1 minute
            */
            break;
        }
    }
    if(flag == 0)
    {
        std::cout << "All runways are busy!! Try after 30 secs" << std::endl;
    }
}
void System::takeOff()
{
    std::string name;
    int weight;
    int totalSeconds;

    std::cout << "Flight name: ";
    std::cin >> name;
    std::cout << "Weight: ";
    std::cin >> weight;

    totalSeconds = computeSecond(name, weight);

    //std::cout << "Provided seconds + 10 : " << totalSeconds << std::endl;

    alloteRunway(name, weight, totalSeconds, true);
}

void System::landing()
{
    std::string name;
    int weight;
    int totalSeconds;

    std::cout << "Flight name: ";
    std::cin >> name;
    std::cout << "Weight: ";
    std::cin >> weight;

    totalSeconds = computeSecond(name, weight);

    alloteRunway(name, weight, totalSeconds, false);
}
