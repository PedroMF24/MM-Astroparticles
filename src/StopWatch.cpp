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
    if (Time / 1e6 >= 60) {
        int total_seconds = static_cast<int>(Time / 1e6);
        int minutes = total_seconds / 60;
        int seconds = total_seconds % 60;
        
        std::cout << "Execution time: " << minutes << " minute" << (minutes != 1 ? "s" : "") 
                    << " and " << seconds << " second" << (seconds != 1 ? "s" : "") << std::endl;
    } else {
        double seconds = Time / 1e6;
        std::cout << "Execution time: " << std::fixed << std::setprecision(3) << seconds 
                    << " second" << (seconds != 1 ? "s" : "") << std::endl;
    }
}

void StopWatch::Lap() {
    StopTimer();
    PrintTime();
    StartTimer();
}


void StopWatch::Break(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}