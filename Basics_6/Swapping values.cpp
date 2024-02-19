#include<bits/stdc++.h>
using namespace std;

void swap(int &n1, int &n2){
		int temp= n1;
		n1= n2;
		n2= temp;
		
	}

	int main(){
		int a=3;
		int b=5;
		cout<<a<<" "<<b<<endl;
		swap(a, b);
		cout<<a<<" "<<b<<endl;
	}