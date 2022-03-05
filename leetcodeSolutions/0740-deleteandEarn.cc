class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      unordered_map<int, int> mp;
      vector<int> new_nums;
      
      new_nums.push_back(nums[0]);
      ++mp[nums[0]];
      for(int i = 1; i < n; ++i){
        ++mp[nums[i]];
        if(nums[i] == new_nums.back()) continue;
        new_nums.push_back(nums[i]);
      }
      
      int new_size = new_nums.size();
      vector<vector<int>> dp(new_size + 1, vector<int>(2));

      dp[1][0] = 0;
      dp[1][1] = new_nums[0]  * mp[new_nums[0]];
      
      for(int i = 2; i < new_size + 1; ++i) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);

        if(new_nums[i - 2] == new_nums[i - 1] - 1){
          dp[i][1] = (new_nums[i - 1] * mp[new_nums[i - 1]]) + dp[i - 1][0];
        }else{
          dp[i][1] = (new_nums[i - 1] * mp[new_nums[i - 1]]) + max(dp[i - 1][0], dp[i - 1][1]);
        }
      }
      
      return max(dp[new_size][0], dp[new_size][1]);
    }
};
