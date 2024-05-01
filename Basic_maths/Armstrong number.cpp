#include <bits/stdc++.h>
using namespace std;

bool checkArmstrong(int n) {
    int count = 0;
    int original_num = n;
    int result = 0;
    int l =to_string(n).length();
    
    while (n > 0) {

        int last_number = n % 10;
        n = n / 10;
        result += pow(last_number, l);
    }
    
    return original_num == result;
}

