#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        //created a list or set of sad users
        unordered_set <int> sadUsers;

        for (auto &friends : friendships){ //jo friends de rkhe hai friendship mein, 
            //me har ek friend ke paas jaungi
            int u= friends[0] - 1; //convert this to 0 based indexing
            int v= friends[1] - 1;

            // u ke sare languages ko dal denge
            // since, u is the vector of vector isilye begin and end lgaya
            unordered_set <int> langSet(begin(languages[u]), end(languages[u]));
            bool canTalk= false;
            for (int lang: languages[v]){
            // check krenge kya koi esa lang hai vo v ke languages ke sath intersect krta ho
                if (langSet.count(lang)){ 
                    canTalk= true;
                    break; //ek bhi common language milgya toh vahi se break kr sakte hai, 
                    //aage check krne ki zrurat hi nhi hai
                }
            }
            // can they canTalk, if not then they are sad users
            if (!canTalk){
                sadUsers.insert(u);
                sadUsers.insert(v);
            }
        }
        //find max known languages among sad users
        vector <int> language (n+1, 0); //there are n lang and count abhi 0 hai
        int mostknowLang= 0;

        for (int user: sadUsers){
            for (int lang: languages[user]){
                language[lang]++;
                mostknowLang= max(mostknowLang, language[lang]);
            }
        }

        return sadUsers.size()-mostknowLang;
    }
};