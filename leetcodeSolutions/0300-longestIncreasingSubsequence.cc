class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
      int n = nums.size();
      //  dp solution
//       vector<int> dp(n, 1);
//       for(int i = 0; i < n; ++i) {
//         for(int j = 0; j < i; ++j) {
//           if(nums[i] > nums[j] && dp[i] <= dp[j]) dp[i] = 1 + dp[j];
//         }
//       }
      
//       return *max_element(dp.begin(), dp.end());
      
      //  greedy with binary search
      vector<int> lis;
      lis.push_back(nums[0]);
      
      for(int i = 1; i < n; ++i) {
        if(lis.back() < nums[i]) lis.push_back(nums[i]);
        else {
          int idx = lower_bound(lis.begin(), lis.end(), nums[i]) - lis.begin();
          lis[idx] = nums[i];
        }
      }
      
      return lis.size();
    }
};
