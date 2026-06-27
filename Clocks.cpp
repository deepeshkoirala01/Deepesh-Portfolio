// ============================================================================ 
/*
* Southern New Hampshire University
* CS-210 Programming Languages
* Module: 3-3 Project One Submission
*
* Author: Deepesh Koirala
* Professor: Joel Driver
* Date: May 24, 2026
*
* Chada Tech Clock Application
*
* Description: This program displays both a 12-hour and a 24-hour clock side by side.
* User can add hours, minutes, or seconds to both clocks or exit the program.
* The program uses modular functions, input validation, and proper rollover logic.
*/
// ============================================================================ 

#include <iostream> 
#include <iomanip> 
using namespace std;

// Function prototypes 
void displayTime(int hours24, int minutes, int seconds);
void addHour(int& hours24);
void addMinute(int& minutes, int& hours24);
void addSecond(int& seconds, int& minutes, int& hours24);
void getInitialTime(int& hours24, int& minutes, int& seconds);
void displayMenu();
int getMenuChoice();

// ============================================================================ 
// Main function - controls program flow 
// ============================================================================ 
int main() {
    int hours24, minutes, seconds;  // Internal time stored in 24-hour format 
    int choice;                     // User's menu selection 

    // Get starting time from user 
    getInitialTime(hours24, minutes, seconds);

    // Main loop - runs until user chooses exit 
    do {
        displayTime(hours24, minutes, seconds);  // Show both clocks 
        displayMenu();                           // Show menu options 
        choice = getMenuChoice();                // Read user's choice 

        // Execute the chosen action 
        switch (choice) {
        case 1:
            addHour(hours24);
            break;
        case 2:
            addMinute(minutes, hours24);
            break;
        case 3:
            addSecond(seconds, minutes, hours24);
            break;
        case 4:
            cout << "\nProgram Ended.\n";
            break;
        default:
            cout << "Invalid choice. Please enter 1-4.\n";
        }
    } while (choice != 4);

    return 0;
}

// ============================================================================ 
// Display both clocks side by side with perfect alignment 
// ============================================================================ 
void displayTime(int hours24, int minutes, int seconds) {
    // Convert to 12-hour format 
    int hours12 = hours24 % 12;
    if (hours12 == 0) hours12 = 12;
    string ampm = (hours24 < 12) ? "AM" : "PM";

    // Top border 
    cout << "\n**************************    **************************\n";
    // Clock titles 
    cout << "*      12-Hour Clock     *    *      24-Hour Clock     *\n";
    // Time display with exact spacing 
    cout << "*      ";
    cout << setw(2) << setfill('0') << hours12 << ":";
    cout << setw(2) << setfill('0') << minutes << ":";
    cout << setw(2) << setfill('0') << seconds << " " << ampm;
    cout << "       *    *      ";
    cout << setw(2) << setfill('0') << hours24 << ":";
    cout << setw(2) << setfill('0') << minutes << ":";
    cout << setw(2) << setfill('0') << seconds;
    cout << "          *\n";
    // Bottom border 
    cout << "**************************    **************************\n";
}

// ============================================================================ 
// Add one hour, wrap at 24 
// ============================================================================ 
void addHour(int& hours24) {
    hours24 = (hours24 + 1) % 24;   // Wrap around after 23 -> 0 
    cout << "\nOne hour added.\n";
}

// ============================================================================ 
// Add one minute, carry to hour if needed 
// ============================================================================ 
void addMinute(int& minutes, int& hours24) {
    minutes++;                       // Increment minutes 
    if (minutes >= 60) {             // Check if minutes need to roll over 
        minutes = 0;                 // Reset minutes to 0 
        addHour(hours24);            // Carry over to hour 
    }
    cout << "\nOne minute added.\n";
}

// ============================================================================ 
// Add one second, carry to minute if needed 
// ============================================================================ 
void addSecond(int& seconds, int& minutes, int& hours24) {
    seconds++;                       // Increment seconds 
    if (seconds >= 60) {             // Check if seconds need to roll over 
        seconds = 0;                 // Reset seconds to 0 
        addMinute(minutes, hours24); // Carry over to minute 
    }
    cout << "\nOne second added.\n";
}

// ============================================================================ 
// Get initial time from user with validation 
// ============================================================================ 
void getInitialTime(int& hours24, int& minutes, int& seconds) {
    cout << "Enter starting time (24-hour format):\n";

    // Validate hours (0-23) 
    do {
        cout << "Hours (0-23): ";
        cin >> hours24;
    } while (hours24 < 0 || hours24 > 23);

    // Validate minutes (0-59) 
    do {
        cout << "Minutes (0-59): ";
        cin >> minutes;
    } while (minutes < 0 || minutes > 59);

    // Validate seconds (0-59) 
    do {
        cout << "Seconds (0-59): ";
        cin >> seconds;
    } while (seconds < 0 || seconds > 59);
}

// ============================================================================ 
// Show menu options 
// ============================================================================ 
void displayMenu() {
    cout << "\n**************************\n";
    cout << "* 1 - Add One Hour       *\n";
    cout << "* 2 - Add One Minute     *\n";
    cout << "* 3 - Add One Second     *\n";
    cout << "* 4 - Exit Program       *\n";
    cout << "**************************\n";
    cout << "Enter your choice: ";
}

// ============================================================================ 
// Read user's menu choice 
// ============================================================================ 
int getMenuChoice() {
    int choice;
    cin >> choice;
    return choice;
}