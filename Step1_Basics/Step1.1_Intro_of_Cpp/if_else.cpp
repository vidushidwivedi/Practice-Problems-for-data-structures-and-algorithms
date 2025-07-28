#include<bits/stdc++.h>
using namespace std;

string compareIfElse(int a, int b) {
	
	if(a<b){
		return "smaller";
	}
	else if (a>b){
		return "greater";
	}
	else if (a==b){
		return "equal";
	}
	return "";
}

void studentGrade (int marks){
	if (marks >= 90){
		cout << "Grade A" << endl;
	}
	else if (marks >= 70){
		cout << "Grade B" << endl;
	}
	else if (marks >= 50){
		cout << "Grade C" <<endl;
	}
		else if (marks >= 35){
		cout << "Grade D" <<endl;
	}
	else {
		cout << "Fail" << endl;
	}
}

int main(){
	int a,b;
	cout<<"Enter two numbers: ";
	cin>>a>>b;
	cout<<compareIfElse(a,b)<< endl;
	int marks;
	cout << "Enter marks: ";
	cin >> marks;
	studentGrade(marks);
	return 0;
}