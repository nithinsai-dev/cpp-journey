//
// Created by NITHIN SAI on 13-06-2026.
//

#include "p13.h";
#include <iostream>;
#include <ctime>;

using namespace std;

int main() {

    srand(time(0));

    int randnum = rand() % 5 +1;

    switch (randnum) {
        case 1:
            cout << "You won a PS5";
            break;
        case 2:
            cout << "You won a XBOX";
            break;
        case 3:
            cout << "You won a Spider-man Game CD";
            break;
        case 4:
            cout << "You won a PS$";
            break;
        case 5:
            cout << "You won a PC";
            break;
    }

    return 0;
}
