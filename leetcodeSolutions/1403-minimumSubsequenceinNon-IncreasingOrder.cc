class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
      sort(nums.rbegin(), nums.rend());
      long long total = accumulate(nums.begin(), nums.end(), 0LL), sum = 0;
      int i = 0;
      while(i < nums.size()) {
        sum += nums[i++];
        
        // sum > total - sum
        if(2 * sum > total) {
          break;
        }
      }
      
      return vector<int>(nums.begin(), nums.begin() + i);
    }
};
