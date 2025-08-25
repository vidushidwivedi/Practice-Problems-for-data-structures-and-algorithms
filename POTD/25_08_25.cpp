#include <bits/stdc++.h>
using namespace std;

//Brute Force
// Time: O(m * n)
// Space: O(1) extra (or O(m * n) including output)


// vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
//     int m = mat.size(), n = mat[0].size();
//     vector<int> result;//Final traversal order will be stored here.
    
//     // There are (m+n-1) diagonals
//     for (int d = 0; d < m + n - 1; d++) {
//         vector<int> temp;//We store current diagonal’s elements here before deciding direction.
        
//         int row = max(0, d - (n - 1));//ensures we don’t start above the bottom row.
//         int col = d - row;//since row+col=d 
        
//         //Traverse along the diagonal
//         while (row < m && col >= 0) {
//             temp.push_back(mat[row][col]);
//             row++;
//             col--;
//         }
//         //Reverse direction if needed
//         if (d % 2 == 0) reverse(temp.begin(), temp.end());
        
//         //Add diagonal to final result
//         result.insert(result.end(), temp.begin(), temp.end());
//     }
    
//     return result;
// }


//Optimal Solution
//Time complexity: O (M * N)
// Space complexity: O (1)
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        //needed constraint first
        if (mat.empty() || mat[0].empty()){
            return {};
        }

        //Initialization
        int m= mat.size();
        int n= mat[0].size();

        vector<int> result(m*n);
        int row= 0;
        int col= 0;

        //Traversal Rules
        for (int i=0; i<m*n; i++){
            result[i]= mat[row][col];

            if ((row+col)%2==0){
                if (col== n-1 ){//Boundary Conditions
                    row++;
                }
                else if (row ==0){//Boundary Conditions
                    col++;
                }
                else {
                    row--;
                    col++;
                }
            }
            else{
                if (row== m-1){//Boundary Conditions
                    col++;
                }
                else if (col == 0){//Boundary Conditions
                    row++;
                }
                else {
                    row++;
                    col--;
                }
            }
        }
        return result;

}
int main() {
    vector<vector<int>> mat = {{1,2,3},{4,5,6},{7,8,9}};
    vector<int> res = findDiagonalOrder(mat);
    
    for (int x : res) cout << x << " ";
    cout << endl;
    
    return 0;
}
