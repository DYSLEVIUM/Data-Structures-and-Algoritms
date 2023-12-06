class Solution {
public:
    int totalMoney(int n) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int ans = 0;

        int complete_weeks = n / 7;
        ans += complete_weeks * (7 * 8) / 2 + (complete_weeks * (complete_weeks - 1) / 2) * 7;

        int incomplete_days = n % 7;
        ans += complete_weeks * incomplete_days + (incomplete_days * (incomplete_days + 1) / 2);

        return ans;
    }
};
