int sumOfAllDivisors(int n){
	int sum=0;

	for(int i=0;i<=n/2;i++){
			if(n%i==0){
				sum+=i;
			}
	}
	return sum;
}