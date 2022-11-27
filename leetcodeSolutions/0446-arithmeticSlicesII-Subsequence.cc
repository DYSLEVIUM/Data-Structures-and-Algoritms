class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        vector<unordered_map<long long, int>> cnt(n); // common difference, count of subsequence >= 2
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                long long d = 1LL * nums[i] - nums[j], sum = 0;
                if (cnt[j].count(d)) sum = cnt[j][d];
                cnt[i][d] += sum + 1; // we are doing += as we take in state from previous iteration and the current
                ans += sum;
            }
        }

        return ans;
    }
};
