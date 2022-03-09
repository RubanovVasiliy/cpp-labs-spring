#pragma once

#include <ctime>
#include <iomanip>
#include <iostream>


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

    inline namespace literals {
        inline Time operator ""_s(uint64_t time) {
            return Time(static_cast<time_t>(time));
        }

        inline Time operator ""_m(uint64_t time) {
            return Time(static_cast<time_t>(time) * seconds_in_minute);
        }

        inline Time operator ""_h(uint64_t time) {
            return Time(static_cast<time_t>(time) * seconds_in_hour);
        }

        inline Time operator ""_d(uint64_t time) {
            return Time(static_cast<time_t>(time) * seconds_in_day);
        }
    }
}