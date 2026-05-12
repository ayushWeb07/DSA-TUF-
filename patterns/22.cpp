// 4 4 4 4 4 4 4
// 4 3 3 3 3 3 4
// 4 3 2 2 2 3 4
// 4 3 2 1 2 3 4
// 4 3 2 2 2 3 4
// 4 3 3 3 3 3 4
// 4 4 4 4 4 4 4

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern22(int n) {
      int limit= (2*n) - 2;

      // 0 -> 2n - 2
      for(int i=0; i<=limit; i++) {

         // 0 -> 2n - 2
         for(int j=0; j<=limit; j++) {

            int topDist= i - 0;
            int bottomDist= limit - i;
            int leftDist= j - 0;
            int rightDist= limit - j;

            int minDist= min({topDist, bottomDist, leftDist, rightDist});
            cout << (n - minDist);

            if(j != limit) {
               cout << " ";
            }
         }

         cout << endl;

      }
   }
};