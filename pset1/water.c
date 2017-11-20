#include <stdio.h>
#include <cs50.h>

int bottles(int minutes);

int main(void) {
    printf("Minutes: ");
    int minutes = get_int();
    printf("Bottles: %d\n", bottles(minutes));
}

// Calculates the amount of water bottles for a given time.
int bottles(int minutes) {
    return minutes * 12;
}
