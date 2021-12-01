class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        const int char_cnt = 256;
        int cache[char_cnt] = {0};
        
        int res = 0;
        for(int r_ptr=0,l_ptr=0;r_ptr<s.length();++r_ptr){
            l_ptr = (cache[s[r_ptr]] > 0) ? max(l_ptr, cache[s[r_ptr]]) : l_ptr;
            cache[s[r_ptr]] = r_ptr + 1;
            res = max(res, r_ptr - l_ptr + 1);
        }
        
        return res;
    }
};
