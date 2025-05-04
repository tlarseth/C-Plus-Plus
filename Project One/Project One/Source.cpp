// CS-210
// Southern New Hampshire Univeristy
// Kyle Mann
// 05/04/2025

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <limits>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;

// Function for clearing the screen to prevent screen clutter
void clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

// Function to format the time to 12 hour format
string format12Hour(int changeUserHours, int changeUserMinutes, int changeUserSeconds) {
    int twelveHour = (changeUserHours % 12 == 0) ? 12 : changeUserHours % 12;
    string ampm = (changeUserHours < 12) ? "AM" : "PM";
    stringstream ss;
    ss << setfill('0') << setw(2) << twelveHour << ":" << setfill('0') << setw(2) << changeUserMinutes << ":" << setfill('0') << setw(2) << changeUserSeconds << " " << ampm;
    return ss.str();
}

// Function to format the time to 24 hour format
string format24Hour(int changeUserHours, int changeUserMinutes, int changeUserSeconds) {
    stringstream ss;
    ss << setfill('0') << setw(2) << changeUserHours << ":" << setfill('0') << setw(2) << changeUserMinutes << ":" << setfill('0') << setw(2) << changeUserSeconds;
    return ss.str();
}

// Function to display the current clocks on the screen
void displayClocks(int changeUserHours, int changeUserMinutes, int changeUserSeconds) {
    cout << "12-Hour: " << format12Hour(changeUserHours, changeUserMinutes, changeUserSeconds) << endl;
    cout << "24-Hour: " << format24Hour(changeUserHours, changeUserMinutes, changeUserSeconds) << endl;
}

// Function to add an hour to current time
void addHour(int& changeUserHours) {
    changeUserHours = (changeUserHours + 1) % 24;
}

// Function to add a minute to current time
void addMinute(int& changeUserMinutes, int& changeUserHours) {
    changeUserMinutes++;
    if (changeUserMinutes == 60) {
        changeUserMinutes = 0;
        addHour(changeUserHours);
    }
}

// Function to add a second to current time
void addSecond(int& changeUserSeconds, int& changeUserMinutes, int& changeUserHours) {
    changeUserSeconds++;
    if (changeUserSeconds == 60) {
        changeUserSeconds = 0;
        addMinute(changeUserMinutes, changeUserHours);
    }
}

// Function to retrieve the current time from user, and convert it to 24 hour format
void getTime12Hour(int& changeUserHours, int& changeUserMinutes, int& changeUserSeconds) {
    bool hourValid = false;
    while (!hourValid) {
        clearScreen();
        cout << "Enter current hour (1-12): ";
        cin >> changeUserHours;
        if (cin.fail() || changeUserHours < 1 || changeUserHours > 12) {
            cout << "Invalid hour. Please enter a value between 1 and 12.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            hourValid = true;
        }
    }

    // Function to get the AM or PM input from user and convert 12 hour times to 24 hour times
    string ampm;
    bool ampmValid = false;
    while (!ampmValid) {
        clearScreen();
        cout << "Enter AM or PM (a/p): ";
        cin >> ampm;
        if (cin.fail() || (tolower(ampm[0]) != 'a' && tolower(ampm[0]) != 'p') || ampm.length() > 2) {
            cout << "Invalid AM/PM. Please enter 'a' or 'p'.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            ampmValid = true;
        }
    }

    if (tolower(ampm[0]) == 'p' && changeUserHours != 12) changeUserHours += 12;
    if (tolower(ampm[0]) == 'a' && changeUserHours == 12) changeUserHours = 0;

    // Function to set initial minute for clock
    bool minuteValid = false;
    while (!minuteValid) {
        clearScreen();
        cout << "Enter current minute (0-59): ";
        cin >> changeUserMinutes;
        if (cin.fail() || changeUserMinutes < 0 || changeUserMinutes > 59) {
            cout << "Invalid minute. Please enter a value between 0 and 59.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            minuteValid = true;
        }
    }

    // Function to set initial seconds for clock
    bool secondValid = false;
    while (!secondValid) {
        clearScreen();
        cout << "Enter current second (0-59): ";
        cin >> changeUserSeconds;
        if (cin.fail() || changeUserSeconds < 0 || changeUserSeconds > 59) {
            cout << "Invalid second. Please enter a value between 0 and 59.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            secondValid = true;
        }
    }
}

// Function to set initial hour for a 24 hour clock
void getTime24Hour(int& changeUserHours, int& changeUserMinutes, int& changeUserSeconds) {
    bool hourValid = false;
    while (!hourValid) {
        clearScreen();
        cout << "Enter current hour (0-23): ";
        cin >> changeUserHours;
        if (cin.fail() || changeUserHours < 0 || changeUserHours > 23) {
            cout << "Invalid hour. Please enter a value between 0 and 23.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            hourValid = true;
        }
    }

    // Function to get the initial minute from user
    bool minuteValid = false;
    while (!minuteValid) {
        clearScreen();
        cout << "Enter current minute (0-59): ";
        cin >> changeUserMinutes;
        if (cin.fail() || changeUserMinutes < 0 || changeUserMinutes > 59) {
            cout << "Invalid minute. Please enter a value between 0 and 59.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            minuteValid = true;
        }
    }

    // Function to get the initial seconds from user
    bool secondValid = false;
    while (!secondValid) {
        clearScreen();
        cout << "Enter current second (0-59): ";
        cin >> changeUserSeconds;
        if (cin.fail() || changeUserSeconds < 0 || changeUserSeconds > 59) {
            cout << "Invalid second. Please enter a value between 0 and 59.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else {
            secondValid = true;
        }
    }
}

// Function for menu structure to output on screen for user
int getUserChoice(int changeUserHours, int changeUserMinutes, int changeUserSeconds) {
    clearScreen();
    displayClocks(changeUserHours, changeUserMinutes, changeUserSeconds);
    cout << endl;
    cout << "\nMenu:" << endl;
    cout << "1 - Add Hour" << endl;
    cout << "2 - Add Minute" << endl;
    cout << "3 - Add Second" << endl;
    cout << "4 - What is the answer to the meaning of Life, the Universe, and Everything?" << endl;
    cout << "5 - Exit" << endl;
    int choice;
    cin >> choice;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter a number between 1 and 5.\n";
        cout << "Press enter to continue...\n";
        cin.get();
        return -1;
    }
    return choice;
}

// Function to handle user input for menu selection
bool handleUserAction(int choice, int& changeUserHours, int& changeUserMinutes, int& changeUserSeconds) {
    switch (choice) {
    case 1:
        addHour(changeUserHours);
        break;
    case 2:
        addMinute(changeUserMinutes, changeUserHours);
        break;
    case 3:
        addSecond(changeUserSeconds, changeUserMinutes, changeUserHours);
        break;

        // Added a question for 4, that if the correct answer is chosen which is a hidden option, then the user gets a fun easter egg.
    case 4:
        cout << "Incorrect" << endl;
        cout << "Press Enter to continue" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        break;
    case 5:
        cout << "Exiting..." << endl;
        return false;

        // Easter Egg for the correct answer to the question asked for input 4
    case 42:
        cout << "Congradulations! You've stumbled upon the answer!" << endl;
        cout << "Remember to..." << endl;
        cout << "  _.--\"\"--._" << endl;
        cout << " .'          `." << endl;
        cout << "/   .--.  .--.  \\" << endl;
        cout << "|    |  |  |  |    |" << endl;
        cout << "\\   `--'  `--'   /" << endl;
        cout << " `. _______ .'" << endl;
        cout << "   //_____\\\\" << endl;
        cout << "  ((  42  ))" << endl;
        cout << "   `------'" << endl;
        cout << "Don't Panic!" << endl;
        cout << "Press Enter to continue" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        break;
    case -1:
        break;
    default:
        cout << "Invalid choice, try again." << endl;
        cout << "Press enter to go back to menu" << endl;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin.get();
        break;
    }
    return true;
}

int main() {

    // Declaring variables
    int changeUserHours = 0, changeUserMinutes = 0, changeUserSeconds = 0;
    int choice;
    string formatInput;
    bool running = true;
    bool formatChoiceValid = false;

    // Function to setup initial clock time
    while (!formatChoiceValid) {
        clearScreen();
        cout << "Are you using 12-hour clock? (y/n)? ";
        cin >> formatInput;

        if (cin.fail()) {
            cout << "Invalid input. Please enter 'y' or 'n'.\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Press enter to continue...\n";
            cin.get();
        }
        else if (formatInput.length() == 1) {
            char formatChoice = tolower(formatInput[0]);
            if (formatChoice == 'y') {
                getTime12Hour(changeUserHours, changeUserMinutes, changeUserSeconds);
                formatChoiceValid = true;
            }
            else if (formatChoice == 'n') {
                getTime24Hour(changeUserHours, changeUserMinutes, changeUserSeconds);
                formatChoiceValid = true;
            }
            else {
                cout << "Invalid input. Please enter 'y' or 'n'.\n";
                cout << "Press enter to continue...\n";
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cin.get();
            }
        }
        else {
            cout << "Invalid input. Please enter a single character 'y' or 'n'.\n";
            cout << "Press enter to continue...\n";
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cin.get();
        }
    }

    //  Calling pre-setup functions to run program with minimal code within main()
    do {
        choice = getUserChoice(changeUserHours, changeUserMinutes, changeUserSeconds);
        running = handleUserAction(choice, changeUserHours, changeUserMinutes, changeUserSeconds);
    } while (running);

    return 0;
}