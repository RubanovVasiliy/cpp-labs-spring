#include "TimeSpan.h"

namespace my_time {
    TimeSpan::TimeSpan(time_t seconds) : seconds_(abs(seconds)) {}

    TimeSpan::TimeSpan(const Time first, const Time second)
            : seconds_(abs(first.getTime() - second.getTime())) {}

    time_t TimeSpan::getSeconds() const { return seconds_; }

    std::ostream &operator<<(std::ostream &os, const TimeSpan &timeSpan) {
        os << std::setfill('0') << std::setw(2) << timeSpan.seconds_ / seconds_in_day << 'd' << ' ';
        os << std::setfill('0') << std::setw(2) << timeSpan.seconds_ / seconds_in_hour % hour_in_day << 'h' << ' ';
        os << std::setfill('0') << std::setw(2) << timeSpan.seconds_ / seconds_in_minute % minute_in_minute << 'm'<< ' ';
        os << std::setfill('0') << std::setw(2) << timeSpan.seconds_ % seconds_in_minute << 's' << '\n';
        return os;
    }

    TimeSpan operator-(const Time &first, const Time &second) {
        return TimeSpan(abs(first.getTime() - second.getTime()));
    }

    TimeSpan operator+(const TimeSpan &first, const TimeSpan &second) {
        return TimeSpan(abs(first.seconds_ + second.seconds_));
    }

    TimeSpan operator-(const TimeSpan &first, const TimeSpan &second) {
        return TimeSpan(abs(first.seconds_ - second.seconds_));
    }

    Time operator+(const Time &time, const TimeSpan &timeSpan) {
        return Time(abs(time.getTime() + timeSpan.seconds_));
    }

    Time operator-(const Time &time, const TimeSpan &timeSpan) {
        return Time(abs(time.getTime() - timeSpan.seconds_));
    }
};