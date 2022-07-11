class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
      int n = nums.size();
      
      vector<int> dp(n);
      dp[0] = nums[0];
//       for(int i = 1; i < n; ++i) {
//         int best = 0;
        
//         //  can be made O(1) using monotonic queue
//         for(int j = 1; j < k + 1; ++j) {
//           if(i - j >= 0) {
//             best = max(best, dp[i - j]);
//           }
//         }
        
//         dp[i] = best + nums[i];
//       }
      
      deque<int> dq { 0 };
      for(int i = 1; i < n; ++i) {
        if(!dq.empty() && dq.front() < i - k) {
          dq.pop_front();
        }
        int best = max(0, dp[dq.front()]);
        dp[i] = best + nums[i];
        
        while(!dq.empty() && dp[dq.back()] <= dp[i]) {
          dq.pop_back();  
        }
        dq.push_back(i);
      }
      
      return *max_element(dp.begin(), dp.end());
    }
};
