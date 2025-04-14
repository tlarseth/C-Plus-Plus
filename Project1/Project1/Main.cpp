#include <iostream>
#include <string>
using namespace std;

int main() {
    string name;

    cout << "What is your name?  ";
    getline(cin, name); // Directly captures the full name, including spaces

    cout << "Your name is " << name << "? That is a weird name." << endl;

    cin.get(); // Pauses until Enter is pressed
    return 0;
}