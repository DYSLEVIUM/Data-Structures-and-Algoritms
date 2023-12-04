class Solution {
public:
    string largestGoodInteger(string num) {
        cin.tie(nullptr)->sync_with_stdio(false);

        constinit static char NINF = '0' - 1;

        char ans = NINF;
        for(int i = 1; i < num.size() - 1; ++i) {
            if (num[i - 1] != num[i] || num[i] != num[i + 1]) {
                continue;
            }
            ans = max(ans, num[i]);
        }

        return ans == NINF ? "" : string(3, ans);
    }
};
