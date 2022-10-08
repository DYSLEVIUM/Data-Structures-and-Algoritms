class Solution {
public:
    int longestContinuousSubstring(string s) {
        int n = s.size();

        int maxx = 0;
        for(int i = 0; i < n; ++i) {
            int j = i + 1;
            while(j < n && s[j] == s[j - 1] + 1) {
                ++j;
            }

            maxx = max(maxx, j - i);
            i = j - 1;
        }

        return maxx;
    }
};
