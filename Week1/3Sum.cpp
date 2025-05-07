#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
        vector<vector<int>> threeSum(vector<int>& nums) {
            //make a duplicate array
            vector<vector<int>>res;
            //sort the existing array
            sort(nums.begin(), nums.end());
            //initialize pointers
            //traverse the entire array
            for(int i=0; i<nums.size(); i++){
                //deal with current i: if it is duplicate
                if (i>0 && nums[i]==nums[i-1]){
                    continue;
                }
                //initialize the other pointers
                int j= i+1;
                int k= nums.size()-1;
                //the condition where it executes
                while (j<k){
                    int total= nums[i]+nums[j]+nums[k];
    
                    if (total>0){
                        k--;
                    }
                    else if (total<0){
                        j++;
                    }
                    else{
                        res.push_back({nums[i], nums[j], nums[k]});
                        j++;
                    
    
                    while (nums[j]==nums[j-1] && j<k){
                        j++;
                    }
                    }
                }
            }
            return res;
        }
    };