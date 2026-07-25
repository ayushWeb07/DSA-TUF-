#include <iostream>
#include <bits/stdc++.h>
using namespace std;

// TC - O(N * log(M)) | SC - O(1)
class Solution {
public:

    // -1 -> mid^N < M   |   0 -> mid^N == M   |   1 -> mid^N > M
    int check_power_status(long long mid, int N, int M) {
        long long ans= 1;

        for(int i=1; i<= N; i++) {
            ans*= mid;

            if(ans > M) return 1;
        }

        if(ans == M) return 0;

        return -1;
    }

    int NthRoot(int N, int M) {
        int st= 1, end= M;
        long long mid;
        int val_status;

        while (st <= end) {
            mid= ((long long)st + end) / 2;

            val_status= check_power_status(mid, N, M);

            // mid^N > M
            if(val_status == 1) {
                end= mid - 1;
            }

            // mid^N < M
            else if(val_status == -1) {
                st= mid + 1;
            }

            else {
                return (int)(mid);
            }
        }

        return -1;
    }
};
