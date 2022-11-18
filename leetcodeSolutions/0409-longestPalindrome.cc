class Solution {
public:
    int longestPalindrome(string s) {
        static constexpr int CHAR_SET = 256;
        
        vector<int> fa(CHAR_SET);
        for(char & ch : s) ++fa[ch];

        int cnt = 0;
        bool contains_odd = false;
        for(int i = 0; i < CHAR_SET; ++i) 
            contains_odd |= fa[i] & 1, cnt += (fa[i] >> 1);

        return (cnt << 1) + contains_odd;
    }
};
