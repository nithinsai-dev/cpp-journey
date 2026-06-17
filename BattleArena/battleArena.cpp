//
// Created by NITHIN SAI on 17-06-2026.
//

#include "battleArena.h"

// ============================================
//  BATTLE ARENA — Basic C++ Concepts Game
//  Concepts: variables, if/else, switch,
//  ternary, while loop, for loop, functions,
//  rand(), input/output
// ============================================

#include <iostream>
#include <string>
#include <cstdlib>   // for rand(), srand()
#include <ctime>     // for time()

using namespace std;

// ── Global constants ──────────────────────
const int MAX_HEALTH   = 100;
const int POTION_HEAL  = 30;
const int POTIONS_MAX  = 3;

// ── Function declarations ─────────────────
void showStatus(string playerName, int playerHP, int enemyHP, int potions);
void showSeparator();

// ─────────────────────────────────────────
//  showStatus — prints HP bars each round
// ─────────────────────────────────────────
void showStatus(string playerName, int playerHP, int enemyHP, int potions) {
    showSeparator();

    // ternary operator — show "DEAD" if HP is 0 or below
    string playerStatus = (playerHP > 0) ? to_string(playerHP) + " HP" : "DEAD";
    string enemyStatus  = (enemyHP  > 0) ? to_string(enemyHP)  + " HP" : "DEAD";

    cout << "  " << playerName << "  :  " << playerStatus << "\n";
    cout << "  Enemy Dragon  :  " << enemyStatus << "\n";
    cout << "  Potions left  :  " << potions << "\n";

    showSeparator();
}

// ─────────────────────────────────────────
//  showSeparator — just a divider line
// ─────────────────────────────────────────
void showSeparator() {
    cout << "\n  ---------------------------------\n";
}

// ─────────────────────────────────────────
//  MAIN
// ─────────────────────────────────────────
int main() {

    // seed random number generator once
    srand(time(0));

    // ── Variables ────────────────────────
    string playerName;
    int    playerHP  = MAX_HEALTH;
    int    enemyHP   = MAX_HEALTH;
    int    potions   = POTIONS_MAX;
    int    round     = 1;
    bool   gameOver  = false;

    // ── Welcome screen ───────────────────
    cout << "\n  ============================\n";
    cout << "       BATTLE ARENA\n";
    cout << "  ============================\n";
    cout << "\n  Enter your hero's name: ";
    cin  >> playerName;

    cout << "\n  Welcome, " << playerName << "!\n";
    cout << "  A Dragon blocks your path.\n";
    cout << "  Defeat it to claim glory!\n";

    // ── 3-enemy selection using FOR loop ─
    //    (pick which enemy type to fight)
    cout << "\n  Choose your enemy:\n";
    string enemies[] = {"Goblin (easy)", "Orc (medium)", "Dragon (hard)"};
    int    enemyHP_choices[] = {60, 80, 100};

    for (int i = 0; i < 3; i++) {
        cout << "  " << (i + 1) << ". " << enemies[i] << "\n";
    }

    int enemyChoice;
    cout << "\n  Your choice (1-3): ";
    cin  >> enemyChoice;

    // ── Conditional to validate choice ───
    if (enemyChoice < 1 || enemyChoice > 3) {
        cout << "  Invalid choice! Defaulting to Dragon.\n";
        enemyChoice = 3;
    }

    enemyHP = enemyHP_choices[enemyChoice - 1];
    string enemyName = enemies[enemyChoice - 1];

    cout << "\n  A " << enemyName << " appears!\n";

    // ═══════════════════════════════════════
    //  MAIN GAME LOOP  (while loop)
    // ═══════════════════════════════════════
    while (!gameOver) {

        cout << "\n  === ROUND " << round << " ===\n";
        showStatus(playerName, playerHP, enemyHP, potions);

        // ── Action menu ──────────────────
        cout << "\n  What will you do?\n";
        cout << "  1. Attack\n";
        cout << "  2. Drink Potion\n";
        cout << "  3. Run Away\n";
        cout << "\n  Your action: ";

        int action;
        cin >> action;

        // ── SWITCH on player action ──────
        switch (action) {

            case 1: {   // ── ATTACK ───────────────────
                // player deals 15–30 damage
                int playerDamage = 15 + rand() % 16;

                // critical hit check (33% chance)
                bool criticalHit = (rand() % 3 == 0);
                if (criticalHit) {
                    playerDamage *= 2;
                    cout << "\n  CRITICAL HIT! You strike for " << playerDamage << " damage!\n";
                } else {
                    cout << "\n  You attack for " << playerDamage << " damage!\n";
                }

                enemyHP -= playerDamage;
                break;
            }

            case 2: {   // ── POTION ───────────────────
                if (potions > 0) {
                    int healed = min(POTION_HEAL, MAX_HEALTH - playerHP);  // don't overheal
                    playerHP  += healed;
                    potions--;
                    cout << "\n  You drink a potion and recover " << healed << " HP!\n";
                } else {
                    cout << "\n  No potions left! Nothing happened.\n";
                }
                break;
            }

            case 3: {   // ── RUN ──────────────────────
                cout << "\n  You fled the battle. Coward!\n";
                gameOver = true;
                break;
            }

            default: {  // ── INVALID ──────────────────
                cout << "\n  Invalid action! You wasted your turn.\n";
                break;
            }
        }

        // ── Check if enemy is dead ───────
        if (enemyHP <= 0) {
            enemyHP = 0;
            cout << "\n  The " << enemyName << " has been defeated!\n";
            cout << "  *** YOU WIN, " << playerName << "! ***\n";
            gameOver = true;
            break;   // exit while loop
        }

        // ── Enemy attacks back ───────────
        // enemy skips turn on round 1 (lets player go first)
        if (!gameOver && round > 1) {
            int enemyDamage = 10 + rand() % 21;  // 10–30 damage

            // if enemy HP is below 30 — it goes berserk!
            if (enemyHP < 30) {
                enemyDamage += 15;
                cout << "\n  The " << enemyName << " is enraged and hits for " << enemyDamage << " damage!\n";
            } else {
                cout << "\n  The " << enemyName << " strikes you for " << enemyDamage << " damage!\n";
            }

            playerHP -= enemyDamage;
        } else if (round == 1) {
            cout << "\n  The " << enemyName << " sizes you up... (enemy skips round 1)\n";
        }

        // ── Check if player is dead ──────
        if (playerHP <= 0) {
            playerHP = 0;
            cout << "\n  You have been defeated!\n";
            cout << "  *** GAME OVER, " << playerName << " ***\n";
            gameOver = true;
        }

        round++;  // increment round counter
    }

    // ── Final result using if/else ───────
    cout << "\n  ---------------------------------\n";
    if (playerHP > 0 && enemyHP <= 0) {
        cout << "  RESULT: VICTORY!\n";
        // ternary — show bonus message based on remaining HP
        string bonus = (playerHP >= 70) ? "Flawless win!" : (playerHP >= 40 ? "Close fight!" : "Barely made it!");
        cout << "  " << bonus << " You finished with " << playerHP << " HP.\n";
    } else if (playerHP <= 0) {
        cout << "  RESULT: DEFEATED\n";
        cout << "  Better luck next time, warrior.\n";
    } else {
        cout << "  RESULT: FLED\n";
        cout << "  A battle left unfinished...\n";
    }

    cout << "  ---------------------------------\n";
    cout << "  Rounds survived: " << round - 1 << "\n\n";

    return 0;
}
