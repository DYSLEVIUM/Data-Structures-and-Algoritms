class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
      unordered_multiset<int> se;
      for(int& num: nums1) se.insert(num);

      vector<int> ans;
      for(int& num: nums2) {
        auto it = se.find(num);
        if(it != se.end()) {
          ans.push_back(num);
          se.erase(it);
        }
      }
      
      return ans;
    }
};
  
