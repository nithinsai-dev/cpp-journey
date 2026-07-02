//
// Created by NITHIN SAI on 02-07-2026.
//

#include "pairs.h"
#include <iostream>

using namespace std;

void explainPairs() {
    pair<int,int> p = {1,3};
    cout << p.first << " " << p.second << endl;

    pair<int,pair<int,int>> p2 = {1,{3,4}};
    cout << p2.first << " " << p2.second.first << " " << p2.second.second <<endl;

    pair<int,int> p3[] = {{1,2},{3,4},{5,6}};
    cout << p3[0].first << " " << p3[0].second << endl;
}

int main() {
    explainPairs();
}