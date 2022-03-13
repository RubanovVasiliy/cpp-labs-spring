#include <time/MyTime.h>
 namespace literals {
     my_time::Time operator ""_s(uint64_t time) {
        return my_time::Time(static_cast<time_t>(time));
    }

     my_time::Time operator ""_m(uint64_t time) {
        return my_time::Time(static_cast<time_t>(time) * my_time::seconds_in_minute);
    }

     my_time::Time operator ""_h(uint64_t time) {
        return my_time::Time(static_cast<time_t>(time) * my_time::seconds_in_hour);
    }

     my_time::Time operator ""_d(uint64_t time) {
        return my_time::Time(static_cast<time_t>(time) * my_time::seconds_in_day);
    }
}