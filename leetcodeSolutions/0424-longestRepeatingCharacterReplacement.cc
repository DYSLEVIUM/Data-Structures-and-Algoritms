class Solution {
public:
    int characterReplacement(string s, int k) {
        int ans = 0, maxf = 0;
        unordered_map<char, int> mp;
        for(int i = 0; i < s.size(); ++i) {
            maxf = max(maxf, ++mp[s[i]]);
            if(ans - maxf < k) ++ans;
            else --mp[s[i - ans]];
        }
        return ans;
    }
};
