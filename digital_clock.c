#include <stdio.h>
#include <time.h>   //for time(), localtime()
#include <unistd.h> //for sleep()
#include <stdlib.h> // for system("clear")
#include <stdbool.h>

int main(void)
{
    int hour, minute, second;

    // get current time from system
    time_t now;
    struct tm *current;

    // get current time in seconds
    time(&now);

    // convert to local time structure
    current = localtime(&now);

    hour = current->tm_hour;
    minute = current->tm_min;
    second = current->tm_sec;

    while (true)
    {
        // clear the screen
        system("clear");

        // print current time
        printf("%02d : %02d : %02d", hour, minute, second);

        // force immediate print
        fflush(stdout);

        // wait 1 second
        sleep(1);

        // increment time
        second++;

        if (second == 60)
        {
            minute++;
            second = 0;
        }
        if (minute == 60)
        {
            hour++;
            minute = 0;
        }
        if (hour == 24)
        {
            hour = 0;
        }
    }

    return 0;
}