class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
      int n = nums.size();
      
      vector<string> ans;
      int l_ptr = 0;
      while(l_ptr < n){
        int r_ptr = l_ptr;
        while(r_ptr + 1 < n && 1 + nums[r_ptr] == nums[r_ptr + 1]){
          ++r_ptr;
        }
        
        if(l_ptr == r_ptr) ans.push_back(to_string(nums[l_ptr]));
        else ans.push_back(to_string(nums[l_ptr]) + "->" + to_string(nums[r_ptr]));
        
        l_ptr = r_ptr + 1;
      }
      
      return ans;
    }
};
