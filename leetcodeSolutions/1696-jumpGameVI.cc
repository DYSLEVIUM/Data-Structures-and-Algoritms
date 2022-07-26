class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
      int n = nums.size();
      
      vector<int> dp(n, INT_MIN);
      dp[0] = nums[0];
      
      //  O(n^2) naive dp
      
      // for(int i = 1; i < n; ++i) {
      //   for(int j = 1; j < k + 1; ++j) {
      //     if(i - j >= 0) {
      //       dp[i] = max(dp[i], nums[i] + dp[i - j]); 
      //     }
      //   }
      // }
      
//       for(int i = 1; i < n; ++i) {
//         int best = INT_MIN;
       
//         //  removing loop invariant, now we just need the max in this window
//         for(int j = 1; j < k + 1; ++j) {
//           if(i - j >= 0) {
//             best = max(best, dp[i - j]); 
//           }
//         }
        
//         dp[i] = best + nums[i];
//       }
      
      deque<int> q{ 0 };
      for(int i = 1; i < n; ++i) {
        if(q.front() < i - k) {
          q.pop_front();
        }
        
        int best = dp[q.front()];
        dp[i] = best + nums[i];
        
        //  monoqueue to find maximum in O(1)
        while(!q.empty() && dp[q.back()] <= dp[i]) {
          q.pop_back();
        }
        q.push_back(i);
      }
      
      return dp[n - 1];
    }
};
