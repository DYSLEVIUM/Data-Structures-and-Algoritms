class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
      int n = nums1.size();
      unordered_map<int, int> mp;
      
      for(auto& num1: nums1){
        for(auto& num2: nums2){
          ++mp[num1+num2];
        }
      }

      int ans = 0;
      for(auto& num3: nums3){
        for(auto& num4: nums4){
          auto it = mp.find(-(num3 + num4));
          if(it!=mp.end()) ans += it->second;
        }
      }
      
      return ans;
    }
};
