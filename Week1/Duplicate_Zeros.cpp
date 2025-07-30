#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        void duplicateZeros(vector<int>& arr){
            int zeros= 0;
            for (int i=0; i<arr.size(); i++){
                if (arr[i]==0){
                    zeros++;
                }
            }
            int i= arr.size()-1;
            int j= arr.size()+ zeros-1;
            while (i!=j){
                if (j < arr.size()) {
                    arr[j] = arr[i]; // Shift current value
                }
                if (arr[i]==0){
                    j--;
                    if (j < arr.size()) {
                        arr[j] = 0; // Duplicate zero
                    }
                }
                i--;
                j--;
            }
        }

};