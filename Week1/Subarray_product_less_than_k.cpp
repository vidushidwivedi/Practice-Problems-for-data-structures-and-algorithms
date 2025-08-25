#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE
//problem: error1- “The product of this subarray got so huge that it didn’t fit in long long anymore.”
// solution: sol1- for (int i = 0; i < n; i++) {
//     long long product = 1;
//     for (int j = i; j < n; j++) {
//         if ((long double)product * nums[j] >= k) break; // stop early
//         product *= nums[j];
//         count++;
//     }
// }

int numSubarrayProductLessThanK (vector<int> & nums, int k){
    int n= nums.size();
    int count= 0; //in order to show the count of the arrays

    //generating every possible subarray
    for (int i=0; i<n; i++){
        for (int j=i; j<n; j++){
            long long product= 1;
            //compute the product of subarray nuns[i..j]
            for (int p=i; p<=j; p++){
                product*=nums[p];
            }
            if (product<k){
                count++;
            }
        }
    }
    return count;
}

int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}