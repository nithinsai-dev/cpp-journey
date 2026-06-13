//
// Created by NITHIN SAI on 13-06-2026.
//

#include "p14.h"
#include <iostream>
#include <ctime>

using namespace std;

int main() {

    srand(time(NULL));
    int number = (rand() % 100) +1;
    bool isRunning = true;
    int guess;
    int guesses = 0;

    while (isRunning) {
        cout << "Enter the number between(1-100) : ";
        cin >> guess;

        if (guess == number) {
            cout << "You Won" << '\n';
            guesses++;
            cout << "The number of guesses : " << guesses << '\n';
            isRunning = false;
        }
        else if (number > guess) {
            cout << "Higher" << '\n';
            guesses++;
        }
        else if (number  <  guess) {
            cout << "Lower" << '\n';
            guesses++;
        }
        else {
            cout << "Please enter a valid number." << '\n';
            guesses++;
        }
    }

    return 0;
}
