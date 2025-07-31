#include <bits/stdc++.h>
using namespace std;

class Solution{
    public:
        int threeSumClosest(vector<int> & nums, int target){
    sort(nums.begin(), nums.end());

    int total= nums[0]+nums[1]+nums[2];
    for (int i=0; i<nums.size(); i++){
        int j= i+1;
        int k= nums.size()-1;

        while (k!=j){
            int sum= nums[i]+nums[j]+nums[k];
            if(abs(target-sum)< abs(target-total)){
                total= sum;
            }

            if (sum<target){
                j++;
            }
            else if (sum>target){
                k--;
            }
            else{
                return target;
            }
        }
    }
    return total;
}
};
