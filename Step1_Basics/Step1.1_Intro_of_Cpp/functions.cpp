//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

// User function Template for C++

class Solution {
  public:
    vector<int> passedBy(int a, int &b) {
        // code here
        //a-> a+1= 2
        //b-> b+2= 4
        a= a+1;
        b=b+2;
        
        return {a,b} ; //imp to use curly brackets in order to return multiple values in vector
        
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int a, b;
        cin >> a >> b;
        Solution obj;
        vector<int> ans = obj.passedBy(a, b);
        cout << ans[0] << " " << ans[1] << "\n";
    
cout << "~" << "\n";
}
    return 0;
}

// } Driver Code Ends