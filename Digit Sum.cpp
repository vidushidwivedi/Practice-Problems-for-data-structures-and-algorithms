#include<bits/stdc++.h>
using namespace std;

int main(){
	int num;
	cin>>num;
	int digit_sum=0;
	while (num>0){
		int last_digit= num % 10;
		digit_sum= digit_sum+last_digit;
		num= num/10;
	}
	cout<<digit_sum<<endl;
    return 0;
}