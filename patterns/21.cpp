// ****
// *  *
// *  *
// ****

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern21(int n) {
      for(int i=1; i<=n; i++) {
         for(int j=1; j<=n; j++) {
            if(i == 1 || i == n) {
               cout << "*";
            }

            else {
               if(j == 1 || j == n) {
                  cout << "*";
               }

               else {
                  cout << " ";
               }
            }
         }

         cout << endl;
      }
   }
};