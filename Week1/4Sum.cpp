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
// vector<vector<int>> fourSum(vector<int>& nums, int target) {
//         int n= nums.size();
//         //set which stores all the codes
//         set<vector<int>> st;
//         //setting up the 3 loops
//         for (int i=0; i<n; i++){
//             for (int j=i+1; j<n; j++){
//                 //create a hashset
//                 // taking bigger data type
//                 // to avoid integer overflow:
//                 set<long long> hashset;
//                 for (int k= j+1; k<n; k++){
//                         long long sum= nums[i]+nums[j];
//                         sum+= nums[k];
//                         long long fourth= target- sum;
//                         if (hashset.find(fourth)!= hashset.end()){
//                             //typecast fourth element into integer type 
//                             vector<int> temp= {nums[i], nums[j], nums[k], (int)fourth};
//                             sort(temp.begin(), temp.end());
//                             st.insert(temp);
//                         }
//                         //VERY IMP: put the kth element into the hashset
//                         hashset.insert(nums[k]);
//                     }
//                 }
//             }
        
        //list of list which will be taking everything that is stored in that set and this will return it
    //     vector<vector<int>> ans (st.begin(), st.end());
    //     return ans;
    // }

//Optimal Approach
//TC: O(n^3) [i= n times, j= n times, k+l= n times]
//SC: O(no of quadruplets)

vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        //created a new array which will store the values
        vector<vector<int>> ans;
        //sorting the og array first
        sort(nums.begin(), nums.end());
        //setting up the loops
        for (int i=0; i<n; i++){ //fixed
            //avoiding duplicates while moving i
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            for (int j=i+1; j<n; j++){ //fixed
            //avoiding duplicates while moving j
            if (j>i+1 && nums[j]==nums[j-1]){  //notice j>i+1
                continue;
            }

            //creating 2 moving pointers
            int k= j+1;
            int l= n-1;
            while (k<l){
                long long sum= nums[i];
                sum+= nums[j];
                sum+= nums[k];
                sum+= nums[l];
                if (sum==target){
                    vector<int> temp= {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    //moving the pts either way 
                    k++;
                    l--;

                    //duplicates while moving k and l
                    while (k<l && nums[k]==nums[k-1]){
                        k++;//remem: increase the position, not skipping it
                    }
                    while (k<l && nums[l]==nums[l+1]){ //see the adjacent location of l
                        l--; //remem: decrease the position, not skipping it
                    } 
                }
                else if (sum>target){
                    l--;
                }
                else {
                    k++;
                }
                }
            } 
        } 
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