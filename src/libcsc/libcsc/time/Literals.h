#include <time/MyTime.h>
 namespace literals {
     my_time::Time operator ""_s(unsigned long long time) {
        return my_time::Time(static_cast<time_t>(time));
    }

     my_time::Time operator ""_m(unsigned long long time) {
        return my_time::Time(static_cast<time_t>(time) * my_time::seconds_in_minute);
    }

     my_time::Time operator ""_h(unsigned long long time) {
        return my_time::Time(static_cast<time_t>(time) * my_time::seconds_in_hour);
    }

     my_time::Time operator ""_d(unsigned long long time) {
        return my_time::Time(static_cast<time_t>(time) * my_time::seconds_in_day);
    }
}