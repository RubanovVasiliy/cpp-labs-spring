#include "MyTime.h"


namespace my_time {
    Time::Time() { time(&time_); }

    Time::Time(time_t time) : time_(time) {}

    time_t Time::getTime() const { return time_; }

    std::ostream &operator<<(std::ostream &os, const Time &time) {
        os << std::setfill('0') << std::setw(2) << time.time_ / seconds_in_day << 'd' << ' ';
        os << std::setfill('0') << std::setw(2) << time.time_ / seconds_in_hour % hour_in_day << 'h' << ' ';
        os << std::setfill('0') << std::setw(2) << time.time_ / seconds_in_minute % minute_in_minute << 'm' << ' ';
        os << std::setfill('0') << std::setw(2) << time.time_ % seconds_in_minute << 's' << '\n';
        return os;
    }

    Time literals::operator ""_s(uint64_t time) {
        return Time(time);
    }

    Time literals::operator ""_m(uint64_t time) {
        return Time(time * seconds_in_minute);
    }

    Time literals::operator ""_h(uint64_t time) {
        return Time(time * seconds_in_hour);
    }

    Time literals::operator ""_d(uint64_t time) {
        return Time(time * seconds_in_day);
    }

    Time literals::operator "" _s(const char*str){
        return Time(*str);
    }
};