#include <bits/stdc++.h>
using namespace std;

//Approach 1: using clear straightforward approach
//tc: o(n^2log n)
//sc: o(n)
class Solution {
public:
    int n;

    // ask the interviewer: can you modify the input?
    // if not, create a copy instead of editing `grid` directly
    void sortDiagonal (int r, int c, vector<vector<int>>& grid, bool asc) {
        vector<int> vec; // diagonal elements starting from (r, c)

        int i = r;
        int j = c;

        while (i < n && j < n) {
            vec.push_back(grid[i][j]);
            i++;
            j++; // important to move along the diagonal
        }

        if (asc) {
            sort(vec.begin(), vec.end());
        } else {
            sort(vec.rbegin(), vec.rend());
        }

        i = r;
        j = c;
        // replace with sorted elements
        for (int &val : vec) {
            grid[i][j] = val;
            i++;
            j++;
        }
    }

    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n = grid.size();

        // Bottom-left (including main diagonal): non-increasing order
        for (int row = 0; row < n; row++) {
            sortDiagonal(row, 0, grid, false);
        }

        // Top-right: non-decreasing order
        for (int col = 1; col < n; col++) {
            sortDiagonal(0, col, grid, true);
        }

        return grid;
    }
};

//using approach 2: by maps
//tc: o(n^2log n)
//sc: o(n^2)
class Solution {
public:
    
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        int n= grid.size();
        unordered_map<int, vector<int>> mp;

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int diag= i-j;
                mp[diag].push_back(grid[i][j]);

            }
        }

        for (auto &it : mp){
            if (it.first>=0){//key
                sort(begin(it.second), end(it.second));
            }else {
                sort(rbegin(it.second), rend(it.second));
            }
        }

        for (int i=0; i<n; i++){
            for (int j=0; j<n; j++){
                int diag= i-j;
                grid[i][j]=mp[diag].back();
                mp[diag].pop_back();
            }
        }
        return grid;
    }
};

int main() {
    Solution sol;

    // Example input
    vector<vector<int>> grid = {
        {1, 7, 3},
        {9, 8, 2},
        {4, 5, 6}
    };

    vector<vector<int>> ans = sol.sortMatrix(grid);

    cout << "Sorted Matrix by Diagonals:\n";
    for (auto &row : ans) {
        for (auto &x : row) {
            cout << x << " ";
        }
        cout << "\n";
    }

    return 0;
}
