#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
    pair<int, char> pr= {5, 'a'};
    cout << pr.first << " " << pr.second << endl;

    pair<char, pair<int, int>> pr2= {'a', {9, 7}};
    cout << pr2.first << " " << pr2.second.first << " " << pr2.second.second;

    return 0;
}