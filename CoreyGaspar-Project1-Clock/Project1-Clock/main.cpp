// Author: Corey Gaspar
// Date: 1/24/2025

#include <iostream>
#include <iomanip> // Formats time output
using namespace std;


// Clock class
class Clock {
    
private:
    // can only be accessed by members of the Clock class
    int hours;
    int minutes;
    int seconds;

public:
    // constructor for the hour, minutes, and seconds inputs
    Clock(int h, int m, int s) : hours(h), minutes(m), seconds(s) {}

    // Add hour function
    void addHour() {
        hours = (hours + 1) % 24;
    }

    // Add minute function
    void addMinute() {
        minutes = (minutes + 1) % 60;
        if (minutes == 0)
        {
            addHour(); // When minutes hits 0, increment the hour
        }
    }

    // Add second function
    void addSecond() {
        seconds = (seconds + 1) % 60;
        if (seconds == 0) 
            addMinute(); // When seconds hits 0, then increment the minute
    }

    // This formats the 12 hour clock with proper spacing
    void Clock12() const {
        int displayHours = hours % 12;
        if (displayHours == 0) displayHours = 12;
        string period = hours >= 12 ? "PM" : "AM";

        cout << "*       " << setw(2) << setfill('0') << displayHours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << " " << period << "       *";
    }

    // This formats the 24 hour clock with proper spacing
    void Clock24() const {
       cout << "       *         " << setw(2) << setfill('0') << hours << ":" << setw(2) << setfill('0') << minutes << ":" << setw(2) << setfill('0') << seconds << "        *\n";
    }
};

// This function displays both the 12 and 24 hour clocks with the proper formatting (borders, spacing)
void displayClocks(const Clock &clock) {
    cout << "***************************       ***************************\n";
    cout << "*      12-Hour Clock      *       *      24-Hour Clock      *\n";
    clock.Clock12(); // calls the functions of each clock which prints them here
    clock.Clock24();
    cout << "***************************       ***************************\n";
}

// Prints the menu that users can use to change the clock with the proper formatting
void userOptions() {
    cout << "***************************\n";
    cout << "*  1 - Add One Hour       *\n";
    cout << "*  2 - Add One Minute     *\n";
    cout << "*  3 - Add One Second     *\n";
    cout << "*  4 - Exit Program       *\n";
    cout << "***************************\n";
}

int main() {
    // Asks user to enter the time
    int h, m, s;
    cout << "Please enter the time (HH MM SS): ";
    cin >> h >> m >> s;

    Clock clock(h, m, s); // Initialize clock with user input

    bool running = true;
    while (running) {
        displayClocks(clock);

        // Asks user to make their choice
        userOptions();
        int choice;
        cin >> choice;

        // Switch statement to handle user choice
        switch (choice) {
        case 1:
            clock.addHour();
            break;
        case 2:
            clock.addMinute();
            break;
        case 3:
            clock.addSecond();
            break;
        case 4:
            running = false;
            break;
        default:
            cout << "Your input is not an option. Please try again.\n";
        }
    }

    cout << "Program ended.\n";
    return 0;
}