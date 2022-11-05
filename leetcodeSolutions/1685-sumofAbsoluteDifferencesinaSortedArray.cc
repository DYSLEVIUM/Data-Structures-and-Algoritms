class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        // |a - b| = +-(a - b) => max(a - b, b - a)
        // as it is sorted, all numbers in front of i are small and all the other on the right are large
        int sum = 0, total = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            sum += nums[i];
            int pre_sum = (i + 1) * nums[i] - sum;
            int suf_sum = (total - sum) - (n - 1 - i) * nums[i];
            ans[i] = pre_sum + suf_sum;
        }

        return ans;
    }
};
