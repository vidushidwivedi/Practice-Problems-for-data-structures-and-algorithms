#include <bits/stdc++.h>
using namespace std;

class Solution { //class
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        for (int i = 0; i < nums.size(); ++i)
            for (int j = i + 1; j < nums.size(); ++j)
                if (nums[i] + nums[j] == target)
                    return {i,j};
        return {};
    }
};
//creating an object of the class Solution and calling the function twoSum
//Solution s;
// s.twoSum(nums, target)

int main() {
    vector<int> nums{2, 7, 11, 15};
    int target = 9;
    
    Solution s;
    vector<int> result= s.twoSum(nums, target);
    for (int i=0; i<result.size(); i++){
        cout << result[i]<< " ";
    }
    // for (int i : Solution().twoSum(nums, target))
    //     cout << i << " ";
    cout << endl;
}


// #include <vector>  // Required for std::vector

// class Solution {
// public:
//     std::vector<int> twoSum(std::vector<int>& nums, int target) {
//         int n = nums.size();
//         for (int i = 0; i <= n - 1; i++) {
//             for (int j = i + 1; j < n; j++) {
//                 if (nums[i] + nums[j] == target) {
//                     return {i, j};
//                 }
//             }
//         }
//         return {};
//     }
// };

//Two pass solution (better approaches ahead)

// class Solution {
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             unordered_map <int, int> NumsMap;
//             int n= nums.size();
            
//             for(int i=0; i<n; i++){
//                 NumsMap[nums[i]]=i;
//             }
    
//             for (int i=0; i< n; i++){
//                 int complement= target - nums[i];
//                 if(NumsMap.count(complement) && NumsMap[complement] != i){
//                     return {i, NumsMap[complement]};
//                 }
//             }
//             return {};
//         }
//     };

//One pass solution (better approach)

// class Solution {
//     public:
//         vector<int> twoSum(vector<int>& nums, int target) {
//             unordered_map <int, int> NumsMap;
//             int n= nums.size();
    
//             for (int i=0; i<n; i++){
//                 int complement= target- nums[i];
//                 if (NumsMap.count(complement)){
//                     return {i, NumsMap[complement]};
//                 }
//                  NumsMap[nums[i]]= i;
//             }
//             return {};
//         }
//     };
