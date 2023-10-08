class Solution {
public:
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        constinit static int INF = 0x3f3f3f;

        int n1 = nums1.size(), n2 = nums2.size();
        vector<vector<int>> dp(n1 + 1, vector<int>(n2 + 1, -INF));

        for(int i = 1; i < n1 + 1; ++i) {
            for(int j = 1; j < n2 + 1; ++j) {
                dp[i][j] = max(nums1[i - 1] * nums2[j - 1] + max(dp[i - 1][j - 1], 0),
                            max(dp[i - 1][j], dp[i][j - 1])
                        );
            }
        }

        return dp[n1][n2];
    }
};
