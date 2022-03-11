class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      auto two_sum = [&nums, &n](const int& start, const int& target) {
        vector<vector<int>> res;

        int lo = start, hi = n - 1;
        while(lo < hi) {
          int curr_sum = nums[lo] + nums[hi];
          
          if(curr_sum < target || (lo > start && nums[lo] == nums[lo - 1])) ++lo;
          else if (curr_sum > target || (hi < n - 1 && nums[hi] == nums[hi + 1])) --hi;
          else res.push_back({nums[lo++], nums[hi--]});
        }
        
        return res;
      };
      
      auto k_sum = [&n, &nums, &two_sum](const auto& k_sum, const int& target, const int& start, const int& k) {
        vector<vector<int>> res;
        
        if(start == n) return res;
        
        int avg_val = target / k;
        
        if(nums[start] > avg_val || avg_val > nums.back()) return res;
        
        if(k == 2) return two_sum(start, target);
        
        for(int i = start; i < n; ++i) {
          if(i == start || nums[i - 1] != nums[i]) {
            for(vector<int>& subset: k_sum(k_sum, target - nums[i], i + 1, k - 1)) {
              res.push_back({nums[i]});
              res.back().insert(res.back().end(), subset.begin(), subset.end());
            }
          }
        }
        
        return res;
      };
      
      return k_sum(k_sum, target, 0, 4);
    }
};
