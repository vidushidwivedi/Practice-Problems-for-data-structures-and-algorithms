
vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
    int m = mat.size(), n = mat[0].size();
    vector<int> result;//Final traversal order will be stored here.
    
    // There are (m+n-1) diagonals
    for (int d = 0; d < m + n - 1; d++) {
        vector<int> temp;//We store current diagonal’s elements here before deciding direction.
        
        int row = max(0, d - (n - 1));//ensures we don’t start above the bottom row.
        int col = d - row;//since row+col=d 
        
        //Traverse along the diagonal
        while (row < m && col >= 0) {
            temp.push_back(mat[row][col]);
            row++;
            col--;
        }
        //Reverse direction if needed
        if (d % 2 == 0) reverse(temp.begin(), temp.end());
        
        //Add diagonal to final result
        result.insert(result.end(), temp.begin(), temp.end());
    }
    
    return result;
}