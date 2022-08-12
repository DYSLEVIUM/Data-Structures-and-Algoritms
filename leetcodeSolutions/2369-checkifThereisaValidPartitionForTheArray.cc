class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
//         vector<int> dp(n, -1);
//         auto solve = [&](const auto &solve, const int &idx)->int{
//             if(idx >= n) {
//                 return 1;
//             }
            
//             if(dp[idx] != -1) {
//                 return dp[idx];
//             }
            
//             bool is_valid = false;
            
//             // first condition
//             if(idx + 1 < n && nums[idx] == nums[idx + 1]) {
//                 is_valid |= solve(solve, idx + 2);
//             }
            
//             // second condition
//             if(idx + 2 < n && nums[idx] == nums[idx + 1] && nums[idx] == nums[idx + 2]) {
//                 is_valid |= solve(solve, idx + 3);
//             }
            
//             // third condition
//             if(idx + 2 < n && nums[idx] == (nums[idx + 1] - 1) && (nums[idx] == nums[idx + 2] - 2)) {
//                 is_valid |= solve(solve, idx + 3);
//             }
            
//             return dp[idx] = is_valid;
//         };
        
//         return solve(solve, 0);
        
        vector<bool> dp(n);
        for(int i = 0; i < n; ++i) {
            bool is_valid = false;
            
            if(i - 1 >= 0)
            is_valid |= (i - 2 >= 0 ? dp[i - 2] : true) && (nums[i] == nums[i - 1]);
            
            if(i - 2 >= 0)
            is_valid |= (i - 3 >= 0 ? dp[i - 3] : true) && (nums[i] == nums[i - 1] && nums[i] == nums[i - 2]);
            
            if(i - 2 >= 0)
            is_valid |= (i - 3 >= 0 ? dp[i - 3] : true) && (nums[i] == nums[i - 1] + 1 && nums[i] == nums[i - 2] + 2);
            
            dp[i] = is_valid;
        }
        return dp[n - 1];
    }
};
