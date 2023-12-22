class Solution {
public:
    int maxScore(const string & s) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int cnt1 = 0;
        for(const char & c : s) {
            cnt1 += c == '1';
        }

        int ans = 0;

        int cnt0 = 0;
        for(int i = 0; i < s.size() - 1; ++i) {
            if(s[i] == '0') {
                ++cnt0;
            } else {
                --cnt1;
            }
            ans = max(ans, cnt0 + cnt1);
        }

        return ans;
    }
};
