//
// Created by NITHIN SAI on 02-07-2026.
//

#include "Vectors.h"
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void explainVector() {
    vector<int> v;
    v.push_back(1);
    v.push_back(2);
    v.emplace_back(3);

    vector<int> v2(5,100); // -> {100,100,100,100,100}

    vector<int> v3(5); //-> size

    // cout << v[0] <<endl;
    vector<int>::iterator it = v2.begin();
    // it++;
    // cout << *it << endl;
    //
    // it += 2;
    // cout << *it << endl;


    //diff iterators :
    //vector<int>::iterator it = v2.end();
    //vector<int>::iterator it = v2.rend();
    //vector<int>::iterator it = v2.rbegin();

    //print an vector :
    // for (vector<int>::iterator it1 = v.begin();it1 != v.end();it++) {
    //     cout << *(it) << " ";
    // }

    // for (auto it1 = v.begin();it1 != v.end();it1++) {  //instead of vector<int>::iterator can use auto
    //     cout << *(it1) << " ";
    // }

    //deletion :
    v2.erase(v2.begin());
    //v2.erase(v2.begin,v2.begin+2);

    //insert function :
    vector<int> v6(7,100);
    // v6.insert(v6.begin(),300);
    v6.insert(v6.end(),2,500); //->2 is no of times and 100 is element


    for (auto it2:v6) {
        cout << it2 << " ";
    };

    // v6.size();
    // v6.pop_back();
    // v6.clear();
    // v6.swap(v);
    // v6.empty();
}

int main() {
    explainVector();
}