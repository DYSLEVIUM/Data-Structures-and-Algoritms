class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        int n = nums.size();

        set<vector<int>> se;
        auto dfs = [&](const auto & dfs, const int & idx, vector<int> & curr){
            if(idx == n) {
                if(!curr.empty() && curr.size() > 1) se.insert(curr);
                return ;
            }

            if(curr.empty()) {
                curr.push_back(nums[idx]);
                dfs(dfs, idx + 1, curr);
                curr.pop_back();
            } else if (curr.back() <= nums[idx]) {
                curr.push_back(nums[idx]);
                dfs(dfs, idx + 1, curr);
                curr.pop_back();
            }

            dfs(dfs, idx + 1, curr);
        };

        vector<int> curr;
        dfs(dfs, 0, curr);

        return vector<vector<int>>(se.begin(), se.end());
    }
};
