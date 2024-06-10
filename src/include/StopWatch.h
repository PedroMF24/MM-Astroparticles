#ifndef __STOPWATCH__
#define __STOPWATCH__

#include <iostream>
#include <chrono>
#include <thread>
#include <iomanip>

using namespace std;
using namespace chrono;

class StopWatch
{
public:
    StopWatch() = default;
    ~StopWatch() = default;

    void StartTimer();
    void StopTimer();
    void ResetTimer();
    void Lap();

    void Break(int seconds);

    void PrintTime();

private:
    high_resolution_clock::time_point start;
    double Time = 0;
};
#endif