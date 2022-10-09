class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        int n = s.size();

        vector<int> ans(n, INT_MAX); // infinite distance
        for(int i = 0; i < 2; ++i) {
            int closest = -1;
            for(int i = n - 1; i >= 0; --i) {
                if(s[i] == c) {
                    closest = i;
                }

                if(closest != -1) {
                    ans[i] = min(ans[i], closest - i);
                }
            }

            // to check left to right and correctness of indicies in ans

            reverse(s.begin(), s.end());
            reverse(ans.begin(), ans.end());
        }

        return ans;
    }
};
