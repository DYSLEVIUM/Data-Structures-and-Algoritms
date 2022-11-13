class Solution {
public:
    int subarrayLCM(vector<int>& nums, int k) {
        int n = nums.size();

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            for(int j = i, lcm = 1; j < n && k % nums[j] == 0; ++ j) {
                lcm = lcm * nums[j] / gcd(lcm, nums[j]);
                ans += lcm == k;
            }
        }

        return ans;
    }
};
