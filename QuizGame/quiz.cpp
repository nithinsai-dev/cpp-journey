//
// Created by NITHIN SAI on 19-06-2026.
//

#include "quiz.h"
#include <iostream>

using namespace std;

int main() {
    string questions[] = {"1.What is C++ ? "  , "2.Which year C++ was created ?  ","3. What is 4099 + 1 ? " , "4.is Earth flat"};

    string options[][4] = {{"A.Programming language" , "B.Framework" , "C.Dont know","D.None of the Above"},
                                {"A.1985","B.1977","C.1966","D.1955"},
                                {"A.5000","B.4100","C.4500","D.4600"},
                                {"A.Yes","B.No","C.Dont know","D.None of the above"}};

    int qSize = sizeof(questions)/sizeof(string);
    int osize = sizeof(options[0])/sizeof(options[0][0]);

    char answerkey[] = {'A','A','B','A'};

    char guess;
    int score = 0;

    for (int i = 0;i<qSize;i++) {
        cout << "*********************\n"  ;
        cout << questions[i] << '\n';
        cout << "*********************\n";

        for (int j=0;j<osize;j++) {
            cout << options[i][j] << '\n';
        }

        cin >> guess;
        guess = toupper(guess);
        if (guess ==answerkey[i]) {
            cout <<  "Correct\n";
            score++;
        } else {
            cout << "Incorrect\n";
            cout << "Answer Key : " << answerkey[i] << '\n';
        }

    }

    cout << "Your score is : " << score << '\n';

    return 0;
}