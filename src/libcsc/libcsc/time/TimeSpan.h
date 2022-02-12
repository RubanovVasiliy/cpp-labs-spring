#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include "MyTime.h"


namespace my_time {

    class TimeSpan {
    private:
        time_t seconds_;
    public:
        explicit TimeSpan(time_t seconds);

        TimeSpan(Time first, Time second);

        time_t getSeconds() const;

        friend std::ostream &operator<<(std::ostream &os, const TimeSpan &timeSpan);

        friend TimeSpan operator-(const Time& first, const Time& second);

        friend TimeSpan operator+(const TimeSpan& first, const TimeSpan& second);

        friend TimeSpan operator-(const TimeSpan& first, const TimeSpan& second);

        friend Time operator+(const Time& time, const TimeSpan& timeSpan);

        friend Time operator-(const Time& time, const TimeSpan& timeSpan);
    };
}
