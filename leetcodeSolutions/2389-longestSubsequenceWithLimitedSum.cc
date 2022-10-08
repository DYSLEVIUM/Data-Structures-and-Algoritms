class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        int m = queries.size(), n = nums.size();

        sort(nums.begin(), nums.end());
        for(int i = 1; i < n; ++i) {
            nums[i] += nums[i - 1];
        }

        vector<int> ans(m);
        for(int i = 0; i < m; ++i) {
            ans[i] = upper_bound(nums.begin(), nums.end(), queries[i]) - nums.begin();
        }

        return ans;
    }
};
