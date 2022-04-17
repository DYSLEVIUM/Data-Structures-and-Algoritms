class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
      unordered_map<int, int> mp;
      
      for(int &task: tasks) {
        ++mp[task];
      }
      
      int ans = 0;
      for(auto &[task, cnt]: mp) {
        if(cnt == 1) {
          return -1;
        } else if(cnt % 3 == 0) {
          ans += cnt / 3;
        } else {
          ans += cnt / 3 + 1;
        }
      }
      
      return ans;
    }
};
