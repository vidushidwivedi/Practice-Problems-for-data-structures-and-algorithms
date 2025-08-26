#include<bits/stdc++.h>
using namespace std;

//Brute Force
//TC= O(n^4)
//SC= O(2*no of quads)
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n= nums.size();
//         //set which stores all the codes
//         set<vector<int>> st;
//         //setting up the 4 loops
//         for (int i=0; i<n; i++){
//             for (int j=i+1; j<n; j++){
//                 for (int k= j+1; k<n; k++){
//                     for (int l= k+1; l<n; l++){
//                         long long sum= nums[i]+nums[j];
//                         //in order to avoid integer limit then typecasting will fail
//                         sum+= nums[k];
//                         sum+= nums[l];
//                         if (sum==target){
//                             //this vector takes only 4 constant size 
//                             vector <int> temp= {nums[i], nums[j], nums[k], nums[l]};
//                             sort (temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
//                     }
//                 }
//             }
//         }
        //list of list which will be taking everything that is stored in that set and this will return it
//         vector<vector<int>> ans (st.begin(), st.end());
//         return ans;
// }


//Better solution
//O(n^3logM)= TC
//O(N)+(2*no of quads)= SC
vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        //set which stores all the codes
        set<vector<int>> st;
        //setting up the 3 loops
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                //create a hashset
                // taking bigger data type
                // to avoid integer overflow:
                set<long long> hashset;
                for (int k= j+1; k<n; k++){
                        long long sum= nums[i]+nums[j];
                        sum+= nums[k];
                        long long fourth= target- sum;
                        if (hashset.find(fourth)!= hashset.end()){
                            //typecast fourth element into integer type 
                            vector<int> temp= {nums[i], nums[j], nums[k], (int)fourth};
                            sort(temp.begin(), temp.end());
                            st.insert(temp);
                        }
                        //VERY IMP: put the kth element into the hashset
                        hashset.insert(nums[k]);
                    }
                }
            }
        
        //list of list which will be taking everything that is stored in that set and this will return it
        vector<vector<int>> ans (st.begin(), st.end());
        return ans;
    }

int main() {
    // Example input
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;

    // Call the function
    vector<vector<int>> result = fourSum(nums, target);

    // Print the result
    cout << "Unique quadruplets that sum to " << target << " are:\n";
    for (auto quad : result) {
        cout << "[ ";
        for (int x : quad) {
            cout << x << " ";
        }
        cout << "]\n";
    }

    return 0;
}