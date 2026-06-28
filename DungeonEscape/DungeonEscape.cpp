//
// Created by NITHIN SAI on 27-06-2026.
//

#include "DungeonEscape.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int health = 100;
int gold = 0;
int room = 1;
bool hasKey = false;

void stats()
{
    cout << "\n---------------------\n";
    cout << "Room   : " << room << endl;
    cout << "Health : " << health << endl;
    cout << "Gold   : " << gold << endl;
    cout << "Key    : " << (hasKey ? "Yes" : "No") << endl;
    cout << "---------------------\n";
}

void monsterRoom()
{
    int damage = rand() % 16 + 10;
    int reward = rand() % 21 + 10;

    cout << "\n A Monster Appears!\n";
    cout << "You fight bravely...\n";

    health -= damage;
    gold += reward;

    cout << "Monster defeated!\n";
    cout << "-" << damage << " HP\n";
    cout << "+" << reward << " Gold\n";
}

void treasureRoom()
{
    int reward = rand() % 41 + 20;

    cout << "\n Treasure Chest!\n";
    cout << "You found " << reward << " gold.\n";

    gold += reward;

    if (!hasKey && rand() % 3 == 0)
    {
        hasKey = true;
        cout << "🔑 You found the dungeon key!\n";
    }
}

void trapRoom()
{
    int damage = rand() % 11 + 10;

    cout << "\n Trap!\n";
    cout << "You lost " << damage << " HP.\n";

    health -= damage;
}

void potionRoom()
{
    int heal = rand() % 16 + 10;

    cout << "\n Health Potion!\n";
    cout << "+" << heal << " HP.\n";

    health += heal;

    if (health > 100)
        health = 100;
}

void emptyRoom()
{
    cout << "\n Empty Room...\n";
    cout << "Nothing happened.\n";
}

int main()
{
    srand(time(0));

    cout << "=============================\n";
    cout << "      DUNGEON ESCAPE\n";
    cout << "=============================\n";

    while (health > 0 && room <= 10)
    {
        stats();

        cout << "\nChoose a door\n";
        cout << "1. Left\n";
        cout << "2. Right\n";
        cout << "Choice: ";

        int choice;
        cin >> choice;

        int event = rand() % 5;

        switch (event)
        {
        case 0:
            monsterRoom();
            break;

        case 1:
            treasureRoom();
            break;

        case 2:
            trapRoom();
            break;

        case 3:
            potionRoom();
            break;

        case 4:
            emptyRoom();
            break;
        }

        if (health <= 0)
            break;

        room++;

        cout << "\nPress Enter to continue...";
        cin.ignore();
        cin.get();
    }

    cout << "\n=============================\n";

    if (health <= 0)
    {
        cout << " GAME OVER!\n";
        cout << "You died in the dungeon.\n";
    }
    else if (hasKey)
    {
        cout << " YOU ESCAPED!\n";
        cout << "You reached the exit with the key.\n";
    }
    else
    {
        cout << " You reached the exit...\n";
        cout << "But you don't have the key!\n";
        cout << "You are trapped forever!\n";
    }

    cout << "\nFinal Stats\n";
    cout << "Health : " << health << endl;
    cout << "Gold   : " << gold << endl;

    return 0;
}