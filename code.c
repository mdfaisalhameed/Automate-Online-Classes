#include <stdio.h>
#include <time.h>
#include <windows.h>

struct timeclock {
    int hour;
    int minutes;
    int seconds;
};

void showClock(struct timeclock *clock);

int main() {
    struct timeclock clock;
    time_t now;
    struct tm *tm_now;
    int hours, i, min, sec, nmbr, hrs[20], minutes[20];
    
    printf("Hello!\nHope you are doing well. Fed up with the daily chore of remembering and logging into online classes?\nHere's a solution!\n");
    printf("Enter the time of your online classes and Google Meet link only once in the morning, and the classes of the whole day will be automated.\n");
    printf("We hope you enjoy the program.\nHave a nice day ahead!\n");
    
    printf("Enter number of online classes today: ");
    scanf("%d", &nmbr);
    
    for (i = 0; i < nmbr; i++) {
        printf("Enter time for class %d (hours and minutes)\nNOTE: Hours should be in 24-hour format\n", i + 1);
        scanf("%d%d", &hrs[i], &minutes[i]);
    }
    
    for (i = 0; i < nmbr; i++) {
        while (1) {
            now = time(NULL);
            tm_now = localtime(&now);
            hours = tm_now->tm_hour;
            min = tm_now->tm_min;
            sec = tm_now->tm_sec;
            
            clock.hour = hours;
            clock.minutes = min;
            clock.seconds = sec;
            
            showClock(&clock);
            printf("Class will start at %d Hours %d minutes\n", hrs[i], minutes[i]);
            
            Sleep(1000);
            system("cls");
            
            if ((hours == hrs[i]) && (min == minutes[i])) {
                Beep(900, 2500);
                system("START https://meet.google.com/");
                break;
            }
        }
    }
    
    return 0;
}

void showClock(struct timeclock *clock) {
    printf("**************Current Time************\n");
    printf("Hour: %d\tMinutes: %d\tSeconds: %d\n", clock->hour, clock->minutes, clock->seconds);
}
