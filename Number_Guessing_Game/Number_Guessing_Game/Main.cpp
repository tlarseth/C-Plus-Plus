#include <iostream>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()
using namespace std;

int main() {
    char playAgain;

    do {
        // Seed the random number generator
        srand(time(0));
        int randomNumber = rand() % 100 + 1; // Generates a random number between 1 and 100
        int userGuess;
        int attempts = 0;

        cout << "Welcome to the Number Guessing Game!" << endl;
        cout << "I'm thinking of a number between 1 and 100. Can you guess what it is?" << endl;

        while (true) {
            cout << "Enter your guess: ";
            if (!(cin >> userGuess)) {  // Input validation to check for non-numeric input
                cin.clear(); // Clear the error flag
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input
                cout << "Invalid input. Please enter a number between 1 and 100." << endl;
                continue;
            }

            attempts++;

            if (userGuess > randomNumber) {
                cout << "Too high! Try again." << endl;
            }
            else if (userGuess < randomNumber) {
                cout << "Too low! Try again." << endl;
            }
            else {
                cout << "Congratulations! You guessed the number in " << attempts << " attempts." << endl;
                break; // Exit the loop once the correct number is guessed
            }
        }

        // Ask the user if they want to play again
        cout << "Would you like to play again? (y/n): ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer before capturing 'y' or 'n'
        cin >> playAgain;

    } while (playAgain == 'y' || playAgain == 'Y');

    cout << "Thanks for playing! Goodbye!" << endl;
    return 0;
}