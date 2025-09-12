class Solution {
public:
    bool doesAliceWin(string s) {
        //what we need to do is:
        // for (char &ch : s){
        //     if (ch== is a vowel){
        //         return true;
        //     }
        // }
        auto lambda= [] (char ch){
            //first way in the below loc
            // return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u';
            return string ("aeiou").find(ch)!= string::npos; //check if the character is present or not from the above input
            //aeiou is the fixed length
          };

        return any_of(begin(s), end(s), lambda); //STL 
    }
};