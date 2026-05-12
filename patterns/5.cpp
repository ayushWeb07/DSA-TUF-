// ****
// ***
// **
// *

#include <iostream>
using namespace std;

class Solution {
public:
    void pattern5(int n) {
        for(int i=n; i>=1; i--) {
            for(int j=i; j>=1; j--) {
                cout << "*";
            }
            cout << endl;
        }
    }
};