int calcGCD(int n, int m){
    long gcd=1;

    for(int i=1; i<=min(n,m); ++i){
        if(n%i==0 && m%i==0){
            gcd= i;
        }
    }
    return gcd;
}