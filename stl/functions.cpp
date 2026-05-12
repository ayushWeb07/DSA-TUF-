#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {

    // vector creation
    vector<int> vec;
    vec.push_back(4);
    vec.push_back(2);
    vec.push_back(1);
    vec.push_back(5);
    vec.push_back(3);

    // 1: sort
    cout << "Before sorting: ";
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }

    sort(vec.begin(), vec.end());

    cout << endl << "After sorting: ";
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }

    // 2: accumulate
    cout << endl << endl << "Sum: " << accumulate(vec.begin(), vec.end(), 0);

    // 3: count the occurance of a value
    cout << endl << endl << "3 is present " << count(vec.begin(), vec.end(), 3) << " times" << endl << endl;

    // 4: check if a value exists
    auto it= find(vec.begin(), vec.end(), 51);

    if (it == vec.end()) {
        cout << "Search failed";
    } else {
        cout << "Search succeeded";
    }

    // 5: next permutation
    string st1= "abc";

    cout << endl << endl << "Next permutations: ";
    do {
        cout << st1 << " ";
    } while (next_permutation(st1.begin(), st1.end()));

    // 6: prev permutation
    string st2= "cba";

    cout << endl << endl << "Prev permutations: ";
    do {
        cout << st2 << " ";
    } while (prev_permutation(st2.begin(), st2.end()));

    // 7: max & min element
    auto max_it= max_element(vec.begin(), vec.end());
    auto min_it= min_element(vec.begin(), vec.end());

    cout << endl << endl << "Max: " << *max_it;
    cout << endl << "Min: " << *min_it;

    // 8: reverse
    cout << endl << endl << "Before reversing: ";
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }

    reverse(vec.begin(), vec.end());

    cout << endl << "After reversing: ";
    for (int i=0; i<vec.size(); i++) {
        cout << vec[i] << " ";
    }

    return 0;
}