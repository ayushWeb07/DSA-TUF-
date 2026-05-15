#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// approach 1: TC - O(n) | SC - O(d) where d -> no. of divisors
class Solution1 {
public:
    vector<int> divisors(int n) {
        vector<int> vec;

        for (int i=1; i<=n; i++) {
            if(n % i == 0) {
                vec.push_back(i);
            }
        }

        return vec;
    }
};

// approach 2: TC - O(sqrt(n)) | SC - O(sqrt(n))
class Solution2 {
public:
    vector<int> divisors(int n) {
        vector<int> vec;
        stack<int> largeStk;

        for (int i=1; i*i<=n; i++) {
            if(n % i == 0) {
                vec.push_back(i);

                if(i != (n / i)) {
                    largeStk.push(n / i);
                }
            }
        }

        while(!largeStk.empty()) {
            vec.push_back(largeStk.top());
            largeStk.pop();
        }

        return vec;
    }
};