class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) 
            return false;
        
        long long original_x = x;
        long long rev_num = 0;
        
        while (x) {
            int last_digit = x % 10;
            rev_num = (rev_num * 10) + last_digit;
            x = x / 10;
        }
        
        return original_x == rev_num;
    }
};
