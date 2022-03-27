class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> te;
      
      for(auto& num: nums2) te.insert(num);

      vector<int> ans1;
      for(auto& num: nums1) {
        if(te.find(num) == te.end()) {
          te.insert(num);
          ans1.push_back(num);
        }
      }
      
      te.clear();
    
      for(auto& num: nums1) te.insert(num);

      vector<int> ans2;
      for(auto& num: nums2) {
        if(te.find(num) == te.end()) {
          te.insert(num);
          ans2.push_back(num);
        }
      }
      
      return {ans1, ans2};
    }
};
