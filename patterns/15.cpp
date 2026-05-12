// ABCD
// ABC
// AB
// A

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern15(int n) {
      for(int i=(65 + n - 1); i>=65; i--) {
         for(int j=65; j<=i; j++) {
            cout << char(j);
         }
         cout << endl;
      }
   }
};