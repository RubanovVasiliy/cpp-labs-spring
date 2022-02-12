#pragma once

#include <ctime>
#include <iostream>
#include <iomanip>


namespace my_time {
    constexpr const int hour_in_day = 24;
    constexpr const int minute_in_minute = 60;
    constexpr const int seconds_in_minute = 60;
    constexpr const int seconds_in_hour = 60 * 60;
    constexpr const int seconds_in_day = 60 * 60 * 24;

    class Time {
    private:
        time_t time_{};

    public:
        Time();
        explicit Time(time_t time);

        time_t getTime() const;

        friend std::ostream &operator<<(std::ostream &os, const Time &time);
    };
}