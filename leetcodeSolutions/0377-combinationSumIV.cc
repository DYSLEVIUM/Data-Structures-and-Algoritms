class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        
        vector<unsigned long long int> dp(target + 1);
        dp[0] = 1;
        for(int i = 1; i < target + 1; ++i) {
            for(auto & num : nums) {
                if(i - num < 0) {
                    break;
                }
                dp[i] += dp[i - num];
            }
        }
        
        return dp[target];
    }
};
