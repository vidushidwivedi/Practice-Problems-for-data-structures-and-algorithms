#include<bits/stdc++.h>
using namespace std;

//Problem: 977 Squares of a Sorted Array
// Link: https://leetcode.com/problems/squares-of-a-sorted-array/description/
class Solution {
    public:
        vector<int> sortedSquares(vector<int>& nums) {
            int n= nums.size();
            for (int i=0; i<=n-1; i++){
                nums[i]= pow(nums[i], 2);
    
            }
            sort(nums.begin(), nums.end());//syntactical learning
            return nums;
        }
    };
//Time complexity: O(nlogn) for sorting the array
//Space complexity: O(1) for sorting the array in place

//Two pointer approach

// class Solution {
//     public:
//         vector<int> sortedSquares(vector<int>& nums) {
//             //step1: make a new array that stores squares
//             vector <int> res(nums.size(),0);//syntactical learning
//             //step2: two pointers ke pre requisites: left and right pointers
//             int left=0;
//             int right= nums.size()-1; //pointing at the end
//             //step3: inserting the elements in the res array from backwards (asending order)
//             for (int i=nums.size()-1; i>=0; i--){
//                 //step4: writing the conditions now + making the absolute check mark
//                 if (abs(nums[left]) > abs(nums[right])){
//                     //step5: add the square of left value in the res array
//                     res[i]= nums[left]*nums[left];
//                     //step6: move forward condition (Always remember)
//                     left++;
//                 }
//                 else {
//                     res[i]= nums[right] * nums[right];
//                     right--;
//                 }
//             }
//             //always remember
//             return res;
//         }
//     };