//
// Created by NITHIN SAI on 29-06-2026.
//

#include "RocketGame.h"
#include <iostream>
using namespace std;

int altitude = 100;
int fuel = 50;
int speed = 20;

void displayStatus()
{
    cout << "\n-----------------------------\n";
    cout << "Altitude : " << altitude << " m\n";
    cout << "Fuel     : " << fuel << " L\n";
    cout << "Speed    : " << speed << " m/s\n";
    cout << "-----------------------------\n";
}

int main()
{
    cout << "=====================================\n";
    cout << "      🚀 ROCKET LANDING GAME\n";
    cout << "=====================================\n";
    cout << "Land the rocket safely!\n";
    cout << "Burn fuel wisely.\n";

    while (altitude > 0)
    {
        displayStatus();

        int burn;
        cout << "\nEnter fuel to burn (0-10): ";
        cin >> burn;

        if (burn < 0)
            burn = 0;

        if (burn > 10)
            burn = 10;

        if (burn > fuel)
            burn = fuel;

        fuel -= burn;

        // Update speed
        speed = speed + 2 - burn;

        if (speed < 1)
            speed = 1;

        // Update altitude
        altitude -= speed;

        if (altitude < 0)
            altitude = 0;
    }

    cout << "\n=====================================\n";
    cout << "Rocket has reached the ground!\n";

    cout << "Landing Speed : " << speed << " m/s\n";

    if (speed <= 5)
    {
        cout << "\n🎉 PERFECT LANDING!\n";
        cout << "Mission Successful!\n";
    }
    else if (speed <= 10)
    {
        cout << "\n🙂 Rough Landing!\n";
        cout << "Rocket survived.\n";
    }
    else
    {
        cout << "\n💥 CRASH!\n";
        cout << "Mission Failed!\n";
    }

    cout << "\nFinal Fuel Left : " << fuel << " L\n";

    return 0;
}