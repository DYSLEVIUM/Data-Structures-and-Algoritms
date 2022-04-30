class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> s_fa(26), t_fa(26);
        for(char &ch: s) {
            ++s_fa[ch - 'a'];
        }
        
        for(char &ch: t) {
            ++t_fa[ch - 'a'];
        }

        int ans = 0;
        for(int i = 0; i < 26; ++i) {
            ans += abs(s_fa[i] - t_fa[i]);  //  taking all the extra letters
        }

        //  as we can convert one letter to another, our overall change now is half of what was before
        ans >>= 1;  
        
        return ans;
    }
};
