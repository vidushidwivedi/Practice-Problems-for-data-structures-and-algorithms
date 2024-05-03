//brute force approach
int sumOfAllDivisors(int n){
	long long result=0;
	for(int i=1; i<=n; i++){
		for(int j=1; j<=i; j++){
			if(i%j==0){
			result+=j;
		}
	}
		
	}
	return result;
}

//optimal approach

