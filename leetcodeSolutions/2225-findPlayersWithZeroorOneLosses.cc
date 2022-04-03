class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
      map<int, int> won, lost;
      
      for(auto& match: matches) {
        ++won[match[0]], ++lost[match[1]];
      }
      
      vector<int> all_won;
      for(auto &[x, y]: won) {
        if(!lost[x]) all_won.push_back(x);
      }
      
      vector<int> one_lost;
      for(auto &[x, y]: lost) {
        if(y == 1) one_lost.push_back(x);
      }

      return {all_won, one_lost};
    }
};
