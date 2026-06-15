//
// Created by NITHIN SAI on 15-06-2026.
//

#include "rps.h"
#include <iostream>
#include <ctime>

char getUserChoice();
char getComputerChoice();
void showChoice(char player , char computer);
void chooseWinner(char player,char computer);

using namespace std;


int main() {
    char player;
    char computer;

    player = getUserChoice();
    computer = getComputerChoice();

    showChoice(player,computer);
    chooseWinner(player,computer);


    return 0;
}

char getUserChoice() {
    char player;
    do {
        cout << "Rock-paper-scissors game \n";
        cout << "*******************************" << '\n';
        cout << "r for rock \n";
        cout << "p for paper \n";
        cout << "s for scissors \n";
        cout << "Enter Your Choice : ";
        cin >> player;
    }while (player != 'r' && player != 'p' && player !='s');

    return player;
}

char getComputerChoice() {
    srand(time(NULL));
    char computer;
    int choice = rand() % 3 + 1;
    switch (choice) {
        case 1:
            computer = 'r';
            break;
        case 2:
            computer = 'p';
            break;
        case 3:
            computer = 's';
            break;
    }
    return computer;
}

void showChoice(char player , char computer)  {
    cout << "Your selection is : " << player << '\n';
    cout << "Computer selection is : " << computer << '\n';
}

void chooseWinner(char player , char computer) {
    switch (player) {
        case 'r':
            if (computer == 'r') {
                cout << "It's a tie \n";
            } else if (computer == 'p') {
                cout << "You lose \n";
            } else {
                cout << "You Win \n";
            }
            break;
        case 'p':
            if (computer == 'p') {
                cout << "It's a tie \n";
            } else if (computer == 's') {
                cout << "You lose \n";
            } else {
                cout << "You Win \n";
            }
            break;
        case 's':
            if (computer == 's') {
                cout << "It's a tie \n";
            } else if (computer == 'r') {
                cout << "You lose \n";
            } else {
                cout << "You Win \n";
            }
            break;
    }

}