//    A
//   ABA
//  ABCBA
// ABCDCBA

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern17(int n) {
      for(int i=1; i<=n; i++) {

         for(int j=1; j<=(n-i); j++) {
            cout << " ";
         }

         for(int j=65; j<=(65 + i -2); j++) {
            cout << char(j);
         }

         cout << char(65 + i - 1);

         for(int j=(65 + i -2); j>=65; j--) {
            cout << char(j);
         }

         cout << endl;
      }
   }
};