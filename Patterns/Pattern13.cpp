#include<bits/stdc++.h>
using namespace std;

void print1(int n){
	for(int i=0; i<n; i++){
		for (int j=0; j<n; j++){
			cout<<"*";
		}
		cout<<endl;
	}
}

void print2(int n){
	for (int i=0; i<n; i++){
		for (int j=0; j<i+1; j++){
			cout<<"*";
		}
		cout<<endl;
	}
}

void print3(int n){
	for (int i=1; i<n+1; i++){
		for (int j=1; j<i+1; j++){
			cout<<j;
		}
		cout<<endl;
	}
}

void print4(int n){
	for (int i=1; i<n+1; i++){
		for (int j=1; j<i+1; j++){
			cout<<i;
		}
		cout<<endl;
	}
}

void print5(int n){
	for (int i=1; i<=n; i++){
		for (int j=0; j<n-i+1; j++){
			cout<<"*";
		}
		cout<<endl;
	}
}

void print6(int n){
	for (int i=1; i<=n; i++){
		for (int j=1; j<=n-i+1; j++){
			cout<<j;
		}
		cout<<endl;
	}
}

void print7(int n){
	for(int i=1; i<=n; i++){
		for (int j=1; j<n-i+1; j++){
			cout<<" ";
		}

		for (int j=2; j<(2*i+1); j++){
			cout<<"*";
		}

		for (int j=1; j<n-i+1; j++){
			cout<<" ";
		}
		cout<<endl;
	}
}

void print8(int n){
	for(int i=0; i<n; i++){
		for (int j=0; j<i; j++){
			cout<<" ";
		}

		for (int j=0; j<2*n-(2*i+1); j++){
			cout<<"*";
		}

		for (int j=0; j<i; j++){
			cout<<" ";
		}
		cout<<endl;
	}
}

void print10(int n){
	for(int i=1; i<=n; i++){
		for (int j=1; j<=i; j++){
			cout<<"*";
		}
		cout<<endl;
	}
}

void print10_ii(int n){
	for(int i=1; i<=n-1; i++){
		for (int j=1; j<=n-i; j++){
			cout<<"*";
		}
		cout<<endl;
	}
}

void print11(int n){

	for(int i=0; i<n; i++){
		int start=1;
		if (i%2==0){
			start=1;
		}
		else{
			start=0;
		}
		for (int j=0; j<=i; j++){
			cout<<start;
			start= 1-start;
		}
		cout<<endl;
	}
}

void print12(int n){
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cout<<j;
		}
		for(int j=1; j<=(2*n-2*i); j++){
			cout<<" ";
		}
		for(int j=i; j>=1; j--){
			cout<<j;
		}
		cout<<endl;
	}
}

void print13(int n){
	int num=1;
	for (int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			cout<< num<< " ";
			num=num+1;
		}
		cout<<endl;
	}
}

int main(){
	int t;
	cin>>t;
	for (int i=0; i<t;i++){
		int n; 
		cin >> n;
		print13(n);
	}	
}
