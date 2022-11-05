class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> pref = nums;
        for(int i = 1; i < n; ++i) pref[i] += pref[i - 1];

        vector<int> ans(n);
        for(int i = 0; i < n; ++i) {
            int pre_sum = (i + 1) * nums[i] - pref[i];
            int suf_sum = (pref[n - 1] - pref[i]) - (n - 1 - i) * nums[i];
            ans[i] = pre_sum + suf_sum;
        }

        return ans;
    }
};
