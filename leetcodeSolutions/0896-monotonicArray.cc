class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
      int n = nums.size();
      if(n == 1) {
        return true;
      }
      
      bool is_increasing = (nums[0] <= nums[n - 1]);
      for(int i = 1; i < n; ++i) {
        if((is_increasing && (nums[i - 1] > nums[i])) || (!is_increasing && (nums[i - 1] < nums[i]))) {
          return false;
        }
      }
      
      return true;
    }
};
