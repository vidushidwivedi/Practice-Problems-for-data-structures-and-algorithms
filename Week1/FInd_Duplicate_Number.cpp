#include<bits/stdc++.h>
using namespace std;

class Solution {
    public:
        int findDuplicate(vector<int> & nums){
            int slow= nums[0];
            int fast= nums[0];
            
            //find the intersection of the cycle
            do{
                slow= nums[slow];
                fast= nums[nums[fast]];
            } while (slow!= fast);


        //find the starting of the cycle
        int slow2= nums[0]; //another 
        do{
            slow= nums[slow];
            slow2= nums[slow2];
        } while (slow!=slow2);

        return slow;

    }
};