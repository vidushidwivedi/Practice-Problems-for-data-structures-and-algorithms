#include<bits/stdc++.h>
using namespace std;

void func(int i, int n){
   
   // Base Condition.
   if(i>n) return;
   cout<<i<<endl;

   // Function call to print i till i increments to n.
   func(i+1,n);

}

int main(){
  
  // Here, let’s take the value of n to be 4.
  int n = 4;
  func(1,n);
  return 0;

}

//codingninjas problem solution 
// #include<bits/stdc++.h>
// using namespace std;

// vector<string> printNTimes(int n) {
// 	vector<string> result;
// 	if(n==0){
// 		return result;
// 	}
// 	result= printNTimes(n-1);
// 	result.push_back("Coding Ninjas");
// 	return result;

// }
