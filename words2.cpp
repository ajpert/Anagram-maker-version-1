#include <iostream>
#include <sstream>
#include <fstream>
#include <boost/algorithm/string.hpp>
#include <string>
#include<bits/stdc++.h>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
    fstream f;
    f.open("english3.txt");
    string words;
    char special;
    unordered_map<char,bool> u;
    cout << "letters: ";
    getline(cin,words);
    cout << "special: ";
    cin >> special;

    for(int i = 0; i < words.size(); i++) {
        u[words[i]] = true;
    }
    u[special] = true;
    string test;
    bool contains = true;
    bool has_special = false;
    while(!f.eof()) {
        f >> test;
        for(int i = 0; i < test.size(); i++) {
            if(test[i] == special) {
                has_special = true;
            }
            if(u[test[i]] != true) {
                contains = false;
                break;
            }
        }
        if(contains == true && has_special == true) {
            cout << test << endl;
        }
        contains = true;
        has_special = false;
    }
}