// 1
// 0 1
// 1 0 1
// 0 1 0 1

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern11(int n) {
      for(int i=1; i<=n; i++) {
         bool f= (i % 2 != 0);
         for(int j=1; j<=i; j++) {
            cout << f << (j != i ? " " : "");
            f= !f;
         }
         cout << endl;
      }
   }
};