class Solution {
public:
    int findMaxLength(vector<int>& nums) {
      int n = nums.size();
      int sum = 0, ans = 0;
      unordered_map<int, int> mp;
      mp[0] = -1;
      for(int i = 0; i < n; ++i) {
        sum += nums[i] == 0 ? -1 : 1;
        if(!mp.count(sum)) {
          mp[sum] = i;
          continue;
        }
        
        ans = max(ans, i - mp[sum]);
      }
      
      return ans;
    }
};
