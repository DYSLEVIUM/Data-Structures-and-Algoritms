class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      unordered_set<int> se;
      for(int &num: nums) {
        se.insert(num);
      }
      
      int longest_streak = 0;
      for(auto &it: se) {
        //  makes sure, we don't check what is already checked
        if(se.find(it - 1) == se.end()) {
          int curr_num = it;
          int curr_streak = 1;
          
          while(se.find(curr_num + 1) != se.end()) {
            ++curr_num, ++curr_streak;
          }
          
          longest_streak = max(longest_streak, curr_streak);
        }
      }
      
      return longest_streak;
    }
};
