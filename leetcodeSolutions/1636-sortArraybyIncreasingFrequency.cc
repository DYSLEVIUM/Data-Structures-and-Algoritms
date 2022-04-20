class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
      unordered_map<int, int> mp;
      
      for(int &num: nums) {
        ++mp[num];
      }
      
      sort(nums.begin(), nums.end(), [&](const int &x, const int &y){
        if(mp[x] == mp[y]) return x > y;
        return mp[x] < mp[y];
      });
      
      return nums;
    }
};
