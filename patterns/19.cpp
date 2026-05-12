// ********
// ***  ***
// **    **
// *      *
// *      *
// **    **
// ***  ***
// ********

#include <iostream>
using namespace std;

class Solution {
public:
   void pattern19(int n) {
      for(int i=n; i>=1; i--) {
         for(int j=i; j>=1; j--) {
            cout << "*";
         }

         for(int j=1; j<=(n-i)*2; j++) {
            cout << " ";
         }

         for(int j=i; j>=1; j--) {
            cout << "*";
         }

         cout << endl;
      }

      for(int i=1; i<=n; i++) {
         for(int j=1; j<=i; j++) {
            cout << "*";
         }

         for(int j=1; j<=(n-i)*2; j++) {
            cout << " ";
         }

         for(int j=1; j<=i; j++) {
            cout << "*";
         }

         cout << endl;
      }
   }
};