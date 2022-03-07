class Solution {
public:
    int jump(vector<int>& nums) {
      int n = nums.size();
      
      //  brute force dp solution
//       vector<int> dp(n, INT_MAX);
//       dp[0] = 0;
//       for(int i = 1; i < n; ++i){
//         dp[i] = 1 + dp[i - 1];
//         for(int j = 0; j < i; ++j){
//           if(j + nums[j] >= i) dp[i] = min(dp[i], 1 + dp[j]);
//         }
//       }
      
//       return dp[n - 1];
      
      //  bfs solution
      int curr_idx = 0, max_reach = 0;
      int curr_reach = 0, jumps = 0;
      while(curr_idx < n - 1){
        max_reach = max(max_reach, curr_idx + nums[curr_idx]);
        
        //  we can go no further without making a jump
        if(curr_idx == curr_reach){
          curr_reach = max_reach;
          ++jumps;
        }
        
        ++curr_idx;
      }
      
      return jumps;
    }
};
