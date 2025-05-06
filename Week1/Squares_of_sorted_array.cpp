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