//parameterised recursion
// long long sumN(long long i, long long sum){
//     if(i<1){;
//         return sum;
//     }
//     return sumN(i-1, sum+i);
// }

// long long sumFirstN(long long n) {
//     return sumN(n, 0);
// }

//functional recursion

long long sumFirstN(long long n){
    if(n==0){
        return n;
    }
    return n + sumFirstN(n-1);
}