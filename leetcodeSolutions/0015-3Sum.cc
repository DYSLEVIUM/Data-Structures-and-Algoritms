class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
      int n = nums.size();
      sort(nums.begin(), nums.end());

      vector<vector<int>> ans;
      for(int i = 0; i < n - 2; ++i) {
        while(i && i < n - 2 && nums[i] == nums[i - 1]) ++i;
        
        int lo = i + 1, hi = n - 1, target = 0 - nums[i];
        while(lo < hi) {
          if(nums[lo] + nums[hi] == target){
            vector<int> curr_ans;
            
            curr_ans.push_back(nums[i]);
            curr_ans.push_back(nums[lo]);
            curr_ans.push_back(nums[hi]);
            
            ans.push_back(curr_ans);

            while(lo < hi && nums[lo] == nums[lo + 1]) ++lo;
            while(lo < hi && nums[hi] == nums[hi - 1]) --hi;
            ++lo, --hi;
          }else if (nums[lo] + nums[hi] < target) ++lo;
          else --hi;
        }
      }
      
      return ans;
    }
};
