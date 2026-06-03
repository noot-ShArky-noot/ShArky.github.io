#include <stdio.h>
#include <stdlib.h>
struct time {
    int hour;
    int minute;
    double second;
};

int main() {
    struct time start = {12, 32, 25.49};
    struct time end   = {15, 12, 17.53};
    struct time elapse;

    printf("start = %02d:%02d:%05.2f\n",
        start.hour, start.minute, start.second);

    printf("end   = %02d:%02d:%05.2f\n",
        end.hour, end.minute, end.second);

    double start_total =
        start.hour * 3600 +
        start.minute * 60 +
        start.second;

    double end_total =
        end.hour * 3600 +
        end.minute * 60 +
        end.second;
    
    double diff = end_total - start_total;

    elapse.hour = (int)(diff / 3600);
    diff -= elapse.hour * 3600;

    elapse.minute = (int)(diff / 60);
    diff -= elapse.minute * 60;
    elapse.second = diff;

    printf("elapse= %02d:%02d:%05.2f\n",
           elapse.hour, elapse.minute, elapse.second);
    return 0;
}