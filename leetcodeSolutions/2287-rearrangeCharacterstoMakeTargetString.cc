class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        const int N = 26;
        vector<int> fa_s(N), fa_t(N);
        
        for(char &ch: s) {
            ++fa_s[ch - 'a'];
        }
        
        for(char &ch: target) {
            ++fa_t[ch - 'a'];
        }
        
        int ans = INT_MAX;
        for(int i = 0; i < N; ++i) {
            if(fa_t[i]) {
                ans = min(ans, fa_s[i] / fa_t[i]);
            }
        }
        
        return ans;
    }
};
