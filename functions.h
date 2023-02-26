#include <iostream>
#include <ctime>
#include <iomanip>

using namespace std;

// Declare and initialize constant int variables for UpdateTime function;
const int ADD_HOUR_MENU_OPTION = 1;
const int ADD_MINUTE_MENU_OPTION = 2;
const int ADD_SECOND_MENU_OPTION = 3;

// FUNCTION: Outputs menu options
void PrintMenu() {
    cout << "\n1 - Add One Hour\n"
        "2 - Add One Minute\n"
        "3 - Add One Second\n"
        "4 - Exit Program\n\n";
}

// FUNCTION: Updates time; Increments minutes/hours when seconds and minutes reach 60, respectively.
void UpdateTime(int selection, int& hours, int& minutes, int& seconds) {
    if (selection == ADD_HOUR_MENU_OPTION) {
        hours++;
    }
    else if (selection == ADD_MINUTE_MENU_OPTION) {
        minutes++;
    }
    else if (selection == ADD_SECOND_MENU_OPTION) {
        seconds++;
    }
    if (seconds >= 60) {
        seconds = 0;
        minutes++;
    }
    if (minutes >= 60) {
        minutes = 0;
        hours++;
    }
    if (hours >= 24) {
        hours = 0;
    }
}

// FUNCTION: Displays time in 12 & 24 hour formats; Includes the logical statements for converting 24-hour format to 12.
void DisplayTime(int hour24, int min, int sec) {
    int hour12;
    string am_pm;
    cout << "\n24-Hour Clock\t\t12-Hour Clock" << endl;
    cout << setw(2) << setfill('0') << hour24 << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << "\t\t";
    am_pm = " AM";
    if (hour24 == 0) {
        hour12 = 12;
    }
    else if (hour24 < 12) {
        hour12 = hour24;
    }
    else if (hour24 == 12) {
        hour12 = 12;
        am_pm = " PM";
    }
    else {
        hour12 = hour24 - 12;
        am_pm = " PM";
    }
    cout << setw(2) << setfill('0') << hour12 << ':' << setw(2) << setfill('0') << min << ':' << setw(2) << setfill('0') << sec << ' ' << am_pm << endl;
}