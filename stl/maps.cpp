#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    map<int, string> mp;
    mp[1]= "khabib";
    mp[3]= "conor";
    mp[4]= "kohli";
    mp[2]= "ronaldo";

    for (auto it: mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << endl;

    // find for 10
    auto it= mp.find(1);

    if (it == mp.end()) {
        cout << "Search failed";
    } else {
        cout << "Search succeeded -> " << (*it).second;
    }

    return 0;
}