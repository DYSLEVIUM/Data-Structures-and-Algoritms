class Solution {
public:
    int rob(vector<int>& nums) {
      int n = nums.size();
      
      if(n == 1) {
        return nums[0];
      }
      
      auto get_max_rob = [&n](const auto &get_max_rob, const vector<int> &nums){
        vector<int> curr(2), prev(2);
        
        // not taking the last
        for(int i = 1; i < n - 1 + 1; ++i) {
          curr[0] = max(prev[0], prev[1]);
          curr[1] = max(nums[i - 1] + prev[0], prev[1]);

          prev = curr;
        }

        return max(curr[0], curr[1]);
      };
      
      // max of don't take last and don't take first as other states are independent
      int ans = max(get_max_rob(get_max_rob, nums), get_max_rob(get_max_rob, vector<int>(nums.rbegin(), nums.rend())));
      
      return ans;
    }
};
