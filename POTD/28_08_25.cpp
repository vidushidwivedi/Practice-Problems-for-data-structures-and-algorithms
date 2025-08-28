class Solution {
public:
    int n;

    //ask the interviewer: can you modify the input?
    // then only modify the input as we're doing the same only which is 'grid'
    // if he doesn't allowed to do so then make changes in the 2d array
    void sortDiagonal (int r, int c, vector<vector<int>>& grid, bool asc){
        vector<int> vec; //diagonal elements starting from r and c

        int i= r;
        int j= c;

        while (i<n && j<n){
            vec.push_back(grid[i][j]);
            i++;
            j++; //imp to remember in order to find the next diagonal elements
        }

        if(asc){
            sort(vec.begin(), vec.end());
        }
        else{
            sort(vec.rbegin(), vec.rend());
        }

        i= r;
        j= c;
        //jaha se ye diagonal elements start huey the bs unki jagah sorted elements lgane hai
        for (int &val: vec){
            grid[i][j]= val;
            i++;
            j++;
        }
    }
    vector<vector<int>> sortMatrix(vector<vector<int>>& grid) {
        n= grid.size();

        //Bottom Left- Non increasing order
        for (int row=0; row<n; row++){// first diagonal index started with 0
            sortDiagonal(row, 0, grid, false);
        } 

        //Top Right- increasing order
        for (int col=1; col<n; col++){ //column started with 1 index
            sortDiagonal(0, col, grid, true);
        } 

        return grid;
    }
};