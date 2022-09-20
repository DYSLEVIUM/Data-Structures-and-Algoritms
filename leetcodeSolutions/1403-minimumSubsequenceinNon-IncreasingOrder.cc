class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
      sort(nums.rbegin(), nums.rend());
      int total = accumulate(nums.begin(), nums.end(), 0), sum = 0, i = 0;
      
      vector<int> ans;
      while(i < nums.size()) {
        ans.push_back(nums[i]);
        sum += nums[i++];
        
        // sum > total - sum
        if(2 * sum > total) {
          break;
        }
      }
      
      return ans;
    }
};
