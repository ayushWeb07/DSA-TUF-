// D
// C D
// B C D
// A B C D

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern18(int n) {
      for(int i=(65 + n - 1); i>=65; i--) {
         for(int j=i; j<=(65 + n - 1); j++) {
            cout << char(j) << " ";
         }
         cout << endl;
      }
   }
};