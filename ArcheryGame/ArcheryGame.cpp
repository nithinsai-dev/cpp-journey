//
// Created by NITHIN SAI on 28-06-2026.
//

#include "ArcheryGame.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int score = 0;

void playRound(int round)
{
    int distance = rand() % 61 + 40;      // 40 - 100 meters
    int wind = rand() % 21 - 10;          // -10 to +10
    int power;

    cout << "\n========================\n";
    cout << "Round " << round << endl;
    cout << "Target Distance : " << distance << " m\n";

    if (wind > 0)
        cout << "Wind : Right (" << wind << ")\n";
    else if (wind < 0)
        cout << "Wind : Left (" << -wind << ")\n";
    else
        cout << "Wind : None\n";

    cout << "\nChoose Power (40 - 100): ";
    cin >> power;

    int finalShot = power + wind;
    int diff = abs(distance - finalShot);

    cout << "\nYour Shot : " << finalShot << " m\n";

    if (diff == 0)
    {
        cout << " PERFECT SHOT!\n";
        score += 10;
    }
    else if (diff <= 3)
    {
        cout << "Excellent Shot!\n";
        score += 8;
    }
    else if (diff <= 7)
    {
        cout << "Good Shot!\n";
        score += 5;
    }
    else if (diff <= 15)
    {
        cout << "Close!\n";
        score += 2;
    }
    else
    {
        cout << "Missed!\n";
    }

    cout << "Current Score : " << score << endl;
}

int main()
{
    srand(time(0));

    cout << "=============================\n";
    cout << "      ARCHERY GAME\n";
    cout << "=============================\n";

    cout << "\nRules:\n";
    cout << "- Target distance changes every round.\n";
    cout << "- Wind affects your arrow.\n";
    cout << "- Enter a power between 40 and 100.\n";
    cout << "- Try to hit the exact distance.\n";

    for (int i = 1; i <= 10; i++)
    {
        playRound(i);
    }

    cout << "\n=============================\n";
    cout << "GAME OVER\n";
    cout << "Final Score : " << score << "/100\n";

    if (score >= 80)
        cout << " Master Archer!\n";
    else if (score >= 60)
        cout << " Great Job!\n";
    else if (score >= 40)
        cout << " Good Effort!\n";
    else
        cout << " Keep Practicing!\n";

    return 0;
}
