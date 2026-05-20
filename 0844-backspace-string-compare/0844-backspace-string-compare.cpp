class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string newS = "", newT = "";
        int count = 0;
        for(int i = s.length()-1; i >= 0; i--){
            if(s[i] == '#') count++;
            else{
                if(count == 0) newS = s[i]+newS;
                else{
                    count--;
                }
            }
        }
        count = 0;
        for(int i = t.length()-1; i >= 0; i--){
            if(t[i] == '#') count++;
            else{
                if(count == 0) newT = t[i]+newT;
                else{
                    count--;
                }
            }
        }
        return newS==newT;
    }
};