#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach: TC - O(log(min(n1, n2))) | SC - O(1)
class Solution {
public:
    int GCD(int n1,int n2) {

        while((n1 != 0) && (n2 != 0)) {

            if(n1 > n2) {
                n1= n1 % n2;
            }

            else {
                n2= n2 % n1;
            }

        }

        return n1 == 0 ? n2 : n1;
    }

    int LCM(int n1,int n2) {
        return (n1 * n2) / GCD(n1, n2);
    }
};