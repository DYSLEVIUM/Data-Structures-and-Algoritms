class Solution {
public:
    Solution(vector<int>& nums) {
      int i = 0;
      for(auto &num : nums) {
        mp[num].push_back(i++);
      }
    }
    
    int pick(int target) {
      return mp[target][rand() % mp[target].size()];   
    }

private:
  unordered_map<int, vector<int>> mp;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * int param_1 = obj->pick(target);
 */
