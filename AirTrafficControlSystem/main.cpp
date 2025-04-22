#include <iostream>
#include <string>
#include <iomanip>

#include "Runway.h"
#include "storage.h"
#include "System.h"

using namespace std;
void createRunways()
{
    Storage::runwayList[1] = Runway(1, false, 40);
    Storage::runwayList[2] = Runway(2, false, 60);
    Storage::runwayList[3] = Runway(3, false, 80);
    Storage::runwayList[4] = Runway(4, false, 90);
}
void createFlight()
{
    Storage::flightMap["ATR"] = Flight("ATR",12,30);
    Storage::flightMap["AirBus"] = Flight("AirBus",20,40);
    Storage::flightMap["Boeing"] = Flight("Boeing",40,50);
    Storage::flightMap["cargo"] = Flight("cargo",100,60);
}
void printFlight()
{
    cout << left << setw(10) << "Flight" << setw(15) << "MaxWeight" << setw(10) << "Max sec" << endl;
    cout << string(30, '-') << endl;
    for(auto x : Storage::flightMap)
    {
        Flight& fly = x.second;
        cout << left << setw(10) << fly.getName() << setw(15)  << fly.getmaxWeight() << setw(10) << fly.getmaxSec() << endl;
    }
}
void printRunways()
{
    std::string status;
    cout << left << setw(10) << "RunwayNo" << setw(10) << "Status" << setw(10) << "Max sec" << endl;
    cout << string(27, '-') << endl;
    for(auto a : Storage::runwayList)
    {
        Runway& run = a.second;
        if(run.getBusy())
        {
            status = "Busy";
        }else
        {
            status = "Free";
        }
        cout << left << setw(10) << run.getNo() << setw(10) << status << setw(10) << run.getMaxTime() << endl;
    }
}
void module()
{
    cout << "\n1.Takeoff\n2.Landing\n3.Emergency landing\n4.Print Runways\n5.Print Flight\n6.Exit\n" << endl;
}
int main()
{
    createRunways();
    createFlight();
    cout << "\t\tAir Traffic Control System!!" << endl;
    bool flag = true;
    int choice = 0;
    System sys;
    while(flag)
    {
        module();
        cin >> choice;
        switch(choice)
        {
        case 1:
            // take off
            sys.takeOff();
            break;
        case 2:
            // Landing
            sys.landing();
            break;
        case 3:
            // Emergency landing
            break;
        case 4:
            // print runways
            printRunways();
            break;
        case 5:
            // print flight
            printFlight();
            break;
        case 6:
            // Exit
            flag = false;
            break;
        default:
            cout << "Invalid Try!!" << endl;
            break;
        }
    }
    return 0;
}
