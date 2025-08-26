class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int n= nums.size();
        //set which stores all the codes
        set<vector<int>> st;
        //setting up the 4 loops
        for (int i=0; i<n; i++){
            for (int j=i+1; j<n; j++){
                for (int k= j+1; k<n; k++){
                    for (int l= k+1; l<n; l++){
                        long long sum= nums[i]+nums[j];
                        //in order to avoid integer limit then typecasting will fail
                        sum+= nums[k];
                        sum+= nums[l];
                        if (sum==target){
                            vector <int> temp= {nums[i], nums[j], nums[k], nums[l]};
                            sort (temp.begin(), temp.end());
                            st.insert(temp);
                        }
                    }
                }
            }
        }




        //list of list which will be taking everything that is stored in that set and this will return it
        vector<vector<int>> ans (st.begin(), st.end());
        return ans;
    }
};