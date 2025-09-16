#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {   // ✅ works in all C++ versions
    return b == 0 ? a : gcd(b, a % b);
}

class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> result; 

        for(int num : nums) {
            while(!result.empty()) {
                int prev = result.back();
                int curr = num;

                int GCD = gcd(prev, curr);
                if(GCD == 1) {
                    break;
                }

                result.pop_back();
                int LCM = prev / GCD * curr;

                num = LCM; 
            }
            result.push_back(num);
        }
        return result;
    }
};
