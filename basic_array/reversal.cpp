#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class Solution{
 public:
     void reverse(int arr[], int n){
         int st= 0, end= n-1;

         while(st < end) {
             swap(arr[st++], arr[end--]);
         }
     }
 };
