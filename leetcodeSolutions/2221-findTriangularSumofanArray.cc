class Solution {
public:
    int triangularSum(vector<int>& nums) {

      vector<int> new_nums(nums.begin(), nums.end());
      while(new_nums.size() != 1) {
        vector<int> curr_nums(new_nums.size() - 1);
        for(int i = 0; i < new_nums.size() - 1; ++i) {
          curr_nums[i] = (new_nums[i] + new_nums[i + 1]) % 10;
        }
        
        new_nums = curr_nums;
      }
      return new_nums[0];
    }
};
