class Solution {
public:
    bool canJump(vector<int>& nums) {
      int n = nums.size();
      
//       //  brute force dp solution
//       vector<int> dp(n, INT_MAX);
//       dp[0] = 0;
//       for(int i = 1; i < n; ++i){
//         dp[i] = 1 + dp[i - 1];
//         for(int j = 0; j < i; ++j){
//           if(j + nums[j] >= i) dp[i] = min(dp[i], 1 + dp[j]);
//         }
//       }
//       return dp[n - 1] != INT_MAX;
      
      int curr_idx = 0, prev_max_reach = 0;
      int max_reach = 0;
      
      while(curr_idx != n - 1){
        max_reach = max(max_reach, curr_idx + nums[curr_idx]);
        
        if(curr_idx == prev_max_reach) prev_max_reach = max_reach;
        if(curr_idx == max_reach) return false; //  if we reach the end and we can't go anywhere
        
        ++curr_idx;
      }
      
      return true;
    }
};
