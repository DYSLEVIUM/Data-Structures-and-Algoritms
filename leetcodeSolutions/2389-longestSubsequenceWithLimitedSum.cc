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
            auto it = upper_bound(nums.begin(), nums.end(), queries[i] - 1);

            ans[i] = it - nums.begin();

            // if we go out of bounds, or we reach an invalid pos
            if(it == nums.end() || *it > queries[i]) {
                --ans[i];
            }

            ++ans[i]; // convert to 1-based
        }

        return ans;
    }
};
