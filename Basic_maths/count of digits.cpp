class Solution {
public:
    int countDigits(int n){
        int a= n;
        int c= 0;
        while (n>0){
            int r= n %10;
            if (a % r==0){
                a++;
            }
            n = n/10;
        }
        return c;
}
};