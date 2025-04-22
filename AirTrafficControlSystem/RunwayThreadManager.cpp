#include "RunwayThreadManager.h"

void RunwayThreadManager::fun(int totalSeconds, int runwayNo)
{
    Storage::runwayList[runwayNo].setBusy(true);
    std::this_thread::sleep_for(std::chrono::seconds(totalSeconds));
    Storage::runwayList[runwayNo].setBusy(false);
}
