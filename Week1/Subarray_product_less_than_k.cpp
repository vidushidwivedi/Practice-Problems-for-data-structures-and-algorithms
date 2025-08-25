#include <bits/stdc++.h>
using namespace std;

//BRUTE FORCE
// int numSubarrayProductLessThanK (vector<int> & nums, int k){
//     int n= nums.size();
//     int count= 0; //in order to show the count of the arrays

//     //generating every possible subarray
//     for (int i=0; i<n; i++){
//         for (int j=i; j<n; j++){
//             long long product= 1;
//             //compute the product of subarray nuns[i..j]
//             for (int p=i; p<=j; p++){
//                 product*=nums[p];
//             }
//             if (product<k){
//                 count++;
//             }
//         }
//     }
//     return count;
// }
//tc= o(n^3)

// BETTER SOLUTION
//in the above, code that's BF but one error will occur which is stated below:

//problem: error1- “The product of this subarray got so huge that it didn’t fit in long long anymore.”
//solving this error will give us the better solution

// solution: sol1- for (int i = 0; i < n; i++) {
//     long long product = 1;
//     for (int j = i; j < n; j++) {
//         if ((long double)product * nums[j] >= k) break; // stop early
//         product *= nums[j];
//         count++;
//     }
// }
//tc= o(n^2)


//Sliding window approach
int numSubarrayProductLessThanK (vector<int> & nums, int k){
    if (k<=1){
        return 0;
    }
    int n= nums.size();
    int left= 0;
    int count= 0;
    long long product= 1;

    //window ke andr jo elements honge unhe multiply krungi: ek ek karke right ptr element ko multiply krti rhugi(i.e, contiguous element)
    for (int right=0; right<n; right++){
        product*= nums[right];

        //agar condition match nahi hoti hai toh mein window ko shrink karungi left forward direction se 
        //imp: use while instead of if becoz hume continuously use shrink krna hai jab tak window ki condition satisfy nahi ho jati
        while (right>left && product>=k ){
            //shrink krugi
            product /= nums[left];
            left++;
        }
        //subarray jo right side par end ho rha hai aur starting se lekr right end tak jo bhi elements hai, men= unhe include kr rhi hu
        count += (right - left + 1); //imp to observe the '+' and '-' symbol
    }
    return count;
}    


int main() {
    vector<int> nums = {10, 5, 2, 6};
    int k = 100;
    cout << numSubarrayProductLessThanK(nums, k) << endl;
    return 0;
}