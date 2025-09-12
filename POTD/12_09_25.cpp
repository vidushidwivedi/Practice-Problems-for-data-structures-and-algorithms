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

            //another way in the below loc
            return string ("aeiou").find(ch)!= string::npos; //check if the character is present or not from the above input
            //aeiou is the fixed length
          }; // remember to put ";"

          

        return any_of(begin(s), end(s), lambda); //STL 
    }
};