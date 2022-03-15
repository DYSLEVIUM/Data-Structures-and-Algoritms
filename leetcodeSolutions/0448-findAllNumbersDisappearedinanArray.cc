class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
      set<int> se;
      for(int i = 1; i <= nums.size(); ++i) se.insert(i);
      for(int& num: nums) se.erase(num);
      
      return vector<int>(se.begin(), se.end());
    }
};
