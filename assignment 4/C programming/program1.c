//Write a program in C to calculate difference between start time and end time of an event. Time is expressed as hr-min-sec. Final result to be produced in seconds
#include <stdio.h>

struct Time {
    int hours;
    int minutes;
    int seconds;
};

int main() {
    struct Time start, end, diff;

    // Input start time
    printf("Enter start time (hh mm ss): ");
    scanf("%d %d %d", &start.hours, &start.minutes, &start.seconds);

    // Input end time
    printf("Enter end time (hh mm ss): ");
    scanf("%d %d %d", &end.hours, &end.minutes, &end.seconds);

    // Convert start time and end time to seconds
    int startInSeconds = start.hours * 3600 + start.minutes * 60 + start.seconds;
    int endInSeconds = end.hours * 3600 + end.minutes * 60 + end.seconds;

    // Calculate difference in seconds
    int diffInSeconds = endInSeconds - startInSeconds;

    // If the difference is negative, it means the event ended the next day
    if (diffInSeconds < 0) {
        diffInSeconds += 24 * 3600;  // Add 24 hours in seconds
    }

    // Convert difference back to hours, minutes, and seconds
    diff.hours = diffInSeconds / 3600;
    diffInSeconds %= 3600;
    diff.minutes = diffInSeconds / 60;
    diff.seconds = diffInSeconds % 60;

    // Output the result
    printf("Difference: %d hours, %d minutes, %d seconds\n", diff.hours, diff.minutes, diff.seconds);
    printf("Total difference in seconds: %d\n", (diff.hours * 3600 + diff.minutes * 60 + diff.seconds));

    return 0;
}