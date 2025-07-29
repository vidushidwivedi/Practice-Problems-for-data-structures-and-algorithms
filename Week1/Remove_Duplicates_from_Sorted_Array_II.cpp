#include<bits/stdc++.h>
using namespace std;

class Solution {
    public: 
        int removeDuplicates(vector<int> & nums){
            if (nums.size() <=2){
                return nums.size();
            }

            int j=2; // position to insert the next unique element

            //i= current element
            //j= position where the next allowed element should be placed.

            for (int i=2; i<nums.size(); i++){
                if (nums[i] != nums[j-2]){ // skip duplicates
                    // If the current element is not equal to the element at j-2,
                nums[j] = nums[i]; // FIXED: write current element to position j
                    j++; //conditionally increment j
                }
            }
            return j; // return the new length of the array
        }
};

int main(){
    Solution solution;
    vector<int> array = {1,1,1,2,2,3};
    int newLength  = solution.removeDuplicates(array);
    cout << "New length of the array: " << newLength << endl;
    cout << "Array after removing duplicates: ";
    for (int i=0; i<newLength; i++){
        cout << array[i] << " ";
    }
    cout << endl;
    return 0; 
}