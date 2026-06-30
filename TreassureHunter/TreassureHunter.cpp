//
// Created by NITHIN SAI on 30-06-2026.
//

#include "TreassureHunter.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int score = 0;
int lives = 5;
int treasures = 0;

void status()
{
    cout << "\n==========================\n";
    cout << "Lives      : " << lives << endl;
    cout << "Score      : " << score << endl;
    cout << "Treasures  : " << treasures << "/3" << endl;
    cout << "==========================\n";
}

int main()
{
    srand(time(0));

    cout << "=====================================\n";
    cout << "      TREASURE HUNTER\n";
    cout << "=====================================\n";

    cout << "\nFind 3 treasures to win!\n";

    while(lives > 0 && treasures < 3)
    {
        status();

        cout << "\nChoose a cave (1-5): ";

        int cave;
        cin >> cave;

        while(cave < 1 || cave > 5)
        {
            cout << "Enter between 1 and 5: ";
            cin >> cave;
        }

        int event = rand()%100;

        if(event < 30)
        {
            cout << "\n💰 TREASURE FOUND!\n";
            score += 10;
            treasures++;
        }
        else if(event < 55)
        {
            cout << "\n💀 A TRAP!\n";
            lives--;
        }
        else if(event < 70)
        {
            cout << "\n❤️ Health Potion!\n";
            lives++;
        }
        else
        {
            cout << "\n😴 Empty Cave.\n";
        }

        if(rand()%10 == 0)
        {
            cout << "\n✨ BONUS CHEST!\n";
            score += 20;
        }
    }

    cout << "\n=====================================\n";

    if(treasures == 3)
    {
        cout << "🏆 YOU WIN!\n";
    }
    else
    {
        cout << "💀 GAME OVER!\n";
    }

    cout << "\nFinal Score : " << score << endl;
    cout << "Treasures   : " << treasures << endl;
    cout << "Lives Left  : " << lives << endl;

    return 0;
}