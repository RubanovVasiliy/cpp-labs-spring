#pragma once

#include "MyTime.h"
#include <cmath>
#include <iomanip>
#include <iostream>


namespace my_time {

    class TimeSpan {
    private:
        time_t seconds_;
    public:
        explicit TimeSpan(time_t seconds);

        TimeSpan(Time first, Time second);

        time_t getSeconds() const;

        friend std::ostream &operator<<(std::ostream &os, const TimeSpan &timeSpan);
    };

    TimeSpan operator-(const Time &first, const Time &second);

    TimeSpan operator+(const TimeSpan &first, const TimeSpan &second);

    TimeSpan operator-(const TimeSpan &first, const TimeSpan &second);

    Time operator+(const Time &time, const TimeSpan &timeSpan);

    Time operator-(const Time &time, const TimeSpan &timeSpan);
}
