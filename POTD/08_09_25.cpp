#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:

//     bool check (int num){
//         while (num){
//             if (num%10==0){
//                 return false;
//             }
//             num/=10;
//         }
//         return true;
//     }
//     vector<int> getNoZeroIntegers(int n) {
//         for (int a=1; a<=n-1; a++){
//             int b= n-a;
//             if (check (a) && check (b)){
//                 return {a,b};
//             }
//         }
//         return {};

//     }
// };
//TC: nlogn
//sc: o(1)

//optimal approach

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        //declare the a and b first
        int a=n;
        int b=0;
        int placeValue= 1;
        //a+b=n
        while (n>1){
            int take=1;
            if (n%10==1){
                take =2;
            }
            a= a-take*placeValue;
            b= b+take*placeValue;
            n= (n-take)/10;
            placeValue*= 10;
        }
        return {a,b};
    }

};
//tc: O(log n)
//sc: O(1)