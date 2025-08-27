#include <bits/stdc++.h>
using namespace std;

int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        long long maxArea= 0;
        long long maxDiag= 0;

        //for iterating the rectangles
        for (int i=0; i<dimensions.size(); i++){
            int l= dimensions[i][0];
            int w= dimensions[i][1];
            long long currDiag= l*l+w*w;
            long long currArea= l*w;

            if (currDiag> maxDiag || (currDiag==maxDiag && currArea> maxArea)){
                maxArea= currArea;
                maxDiag= currDiag;
            }
        }
        return (int)maxArea; //returning this as int
}
int main() {
    // Example Input
    vector<vector<int>> dimensions = {{9, 3}, {8, 6}};

    // Function call
    int result = areaOfMaxDiagonal(dimensions);

    // Output
    cout << "Maximum Area of Rectangle with Longest Diagonal: " << result << endl;

    return 0;
}