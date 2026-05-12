#include <iostream>
#include <string>
#include <bits/stdc++.h>
using namespace std;

int main() {
    multimap<int, string> mp;
    mp.insert({1, "khabib"});
    mp.insert({3, "conor"});
    mp.insert({4, "kohli"});
    mp.insert({2, "ronaldo"});
    mp.insert({1, "islam"});
    mp.insert({3, "khamzat"});

    for (auto it: mp) {
        cout << it.first << " -> " << it.second << endl;
    }

    cout << endl;

    // find for a value
    auto it= mp.find(1);

    if (it == mp.end()) {
        cout << "Search failed";
    } else {
        cout << "Search succeeded -> " << (*it).second;
    }

    cout << endl << endl;

    // find all values for a key
    auto itr= mp.equal_range(3);

    for (auto i=itr.first; i!=itr.second; i++) {
        cout << (*i).first << " -> " << (*i).second << endl;
    }

    return 0;
}