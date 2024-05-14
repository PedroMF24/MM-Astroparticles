#include "include/StopWatch.h"

void StopWatch::StartTimer() {
    start = high_resolution_clock::now();
}

void StopWatch::StopTimer() {
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    Time += duration.count();
}

void StopWatch::ResetTimer()
{
    start = high_resolution_clock::time_point();
    Time = 0.0;
    cout << "Timer reset..." << endl;
}

void StopWatch::PrintTime() {
    if (Time/1e6 >= 60) {
        cout << "Execution time: " << fixed << setprecision(3) << Time/(1e6*60) << " minutes" << endl;
    } else {
        cout << "Execution time: " << fixed << setprecision(3) << Time/1e6 << " seconds" << endl;
    }
}

void StopWatch::Lap() {
    StopTimer();
    PrintTime();
    StartTimer();
}