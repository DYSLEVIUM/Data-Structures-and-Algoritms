class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
      int n = nums.size();
      
      vector<int> ans;
      for(int i = 0; i < n; ++i) {
        while(!ans.empty() && ans.back() > nums[i] && (n - i + ans.size() > k)) {
          ans.pop_back();
        }
        
        // if we can make a move, we make it
        if(ans.size() < k) {
          ans.push_back(nums[i]);
        }
      }
      
      return ans;
    }
};
