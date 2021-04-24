class Solution {
public:
    bool isSubsequence(string s, string t) {
        int sI = s.length()-1;
        int tI = t.length()-1;
        
        int cnt = 0;
        while(s!=t && tI >= 0 && sI >= 0){
            if(s[sI] == t[tI]){
                --sI;
                --tI;
                ++cnt;
            }else{
                --tI;
            }
        }
        
        return cnt == s.length();
    }
};
