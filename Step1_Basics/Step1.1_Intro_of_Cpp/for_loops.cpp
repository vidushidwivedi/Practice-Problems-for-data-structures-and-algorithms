#include<bits/stdc++.h>
using namespace std;

int fibonacci(int n){
        if (n==1 || n==2){
                return 1;
        }
        int prev1=1;
        int prev2=1;
        int curr=0;
        for(int i=3;i<=n;i++){
                curr= prev1+prev2;
                prev2= prev1;
                prev1= curr;
        }
        return curr;
}

int main()
{
        /*
        *  Write your code here. 
         *  Read input as specified in the question.
         *  Print output as specified in the question.
        */
        int n;
        cin>>n;
        cout<<fibonacci(n)<<endl;
        return 0;

}