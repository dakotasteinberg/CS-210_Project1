/*
 * NAME: Dakota Steinberger
 * COURSE: CS-210
 * ASSIGNMENT: Project 1
 */

#include <ctime>
#include <iostream>
#include "functions.h" // Moved functions into a separate header file for cleanliness in the main file.

using namespace std;

int main() {
    // Declare and initialize constant int variable for exiting while loop.
    const int EXIT_MENU_OPTION = 4;

    // Declaring variables to store user selection and local time
    int userSelection;
    int hour24;
    int min;
    int sec;

    // Using ctime library to get time
    time_t curr_time;
    curr_time = time(nullptr);

    // Using ctime library to get local time
    tm* tm_local = localtime(&curr_time);
    hour24 = tm_local->tm_hour; // Hours; 0-23
    min = tm_local->tm_min; // Minutes; 0-59
    sec = tm_local->tm_sec; // Seconds; 0-59

    // Print the menu for the first time.
    PrintMenu();

    // Capture the user's first selection.
    cin >> userSelection;

    // While the user has NOT input 4, update the time, display the time, and display the menu.
    while (userSelection != EXIT_MENU_OPTION) {
        UpdateTime(userSelection, hour24, min, sec); // Update the time based on userSelection value AND local time (hour24, min, sec) defined above.
        DisplayTime(hour24, min, sec); // Display the time
        PrintMenu(); // Display the menu
        cin >> userSelection; // Capture user selection
    }
    return 0;
}