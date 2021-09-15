class Solution {
public:
    int countSubstrings(string s, string t) {
        int ans = 0;
        
        for(int i = 0; i < s.length(); ++i){
            for(int j = 0;j < t.length(); ++j){
                int diff = 0;
                for(int k = 0; i + k < s.length() && j + k < t.length(); ++k){
                    if(s[i + k] != t[j + k]) ++diff;
                    
                    if(diff > 1) break;
                    
                    ans += diff;
                }
            }
        }
        
        return ans;
    }
};
