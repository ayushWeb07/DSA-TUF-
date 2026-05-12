// A
// BB
// CCC
// DDDD

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern16(int n) {
      for(int i=65; i<=(65 + n - 1); i++) {
         for(int j=65; j<=i; j++) {
            cout << char(i);
         }
         cout << endl;
      }
   }
};