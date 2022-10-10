class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int n = nums.size(), ans = 0, maxx = INT_MIN;
        auto dfs = [&](const auto &dfs, const int &idx, const int &orr){
            if(idx == n) {
                if(orr == maxx) {
                    ++ans;
                } else if(orr > maxx) {
                    ans = 1;
                    maxx = orr;
                }
                return ;
            }

            dfs(dfs, idx + 1, orr); // don't take
            dfs(dfs, idx + 1, orr | nums[idx]); // take
        };
        recur(recur, 0, 0);

        return ans;
    }
};
