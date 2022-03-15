class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
      unordered_set<int> se;
      for(int& num: nums1) se.insert(num);

      unordered_set<int> ans;
      for(int& num: nums2) if(se.find(num) != se.end()) ans.insert(num);
      
      return vector<int>(ans.begin(), ans.end());
    }
};
