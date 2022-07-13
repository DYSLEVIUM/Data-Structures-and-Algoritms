class Solution {
public:
    bool canPartition(vector<int>& nums) {
      int n = nums.size();
      
      int sum = accumulate(nums.begin(), nums.end(), 0);
      int target = sum / 2;
      
      //  impossible conditions
      if(n < 2 || target * 2 != sum || *max_element(nums.begin(), nums.end()) > target) {
        return false;
      }
      
      vector<bool> prev(target + 1), curr(target + 1);
      for(int i = 0; i < n + 1; ++i) {
        for(int j = 0; j < target + 1; ++j) {
          if(!i || !j) {
            if(!i && !j) {
              curr[j] = true;
            } else if(!i) {
              curr[j] = false;
            } else {
              curr[j] = true;
            }
            continue;
          }
          
          if(j - nums[i - 1] >= 0) {
            curr[j] = prev[j] || prev[j - nums[i - 1]];
          } else {
            curr[j] = prev[j];
          }
        }
        
        prev = curr;
      }
      
      return curr[target];
    }
};
