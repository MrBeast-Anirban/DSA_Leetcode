// Two pointer technique.

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1, j = t.size()-1;
        int skips = 0, skipt = 0;
        while(i >= 0 || j >= 0){
            //find the position of next character in string s
            while(i >= 0){
                if(s[i] == '#'){
                    skips++, i--;
                }
                else if(skips > 0){
                    skips--, i--;
                }
                else break;
            }
            // find position of next character in string t
            while(j >= 0){
                if(t[j] == '#'){
                    skipt++, j--;
                }
                else if(skipt > 0){
                    skipt--, j--;
                }
                else break;
            }
            //If two actual characters are different
            if(i >= 0 and j >= 0 and s[i] != t[j]) return false;
            //If expecting to compare the character vs nothing
            if((i >= 0) != (j >= 0)) return false;
            i--, j--;
        }
        return true;
    }
};