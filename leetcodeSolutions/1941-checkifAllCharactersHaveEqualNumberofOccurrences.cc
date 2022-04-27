class Solution {
public:
    bool areOccurrencesEqual(string s) {
        int cnt = 0;
        vector<int> fa(26);
        for(auto &ch: s) {
            cnt = max(cnt, ++fa[ch - 'a']);
        }
        
        for(int i = 0; i < 26; ++i) {
            if(!fa[i]) continue;
            if(fa[i] != cnt) return false;
        }
        
        return true;
    }
};
