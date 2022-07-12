class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
      int n = matchsticks.size();
      
      int perimeter = accumulate(matchsticks.begin(), matchsticks.end(), 0);
      int side_len = perimeter / 4;
      
      //  impossible conditions
      if(n < 4 || perimeter % 4 || *max_element(matchsticks.begin(), matchsticks.end()) > side_len) {
        return false;
      }
      
      vector<int> cache(1 << n, -1);
      auto can_make_sets = [&](const auto &can_make_sets, const int &mask, const int &sides_left, const int &curr_sum){
        if(sides_left == 0) {
          return true;
        }
        if(curr_sum == side_len) {
          return can_make_sets(can_make_sets, mask, sides_left - 1, 0);
        }
        
        if(cache[mask] != -1) {
          return !!cache[mask];
        }
        
        for(int i = 0; i < n; ++i) {
          //  if this matchstick is not taken and curr_sum + matchsticks[i] <= side_len
          if((mask & (1 << i)) == 0 && curr_sum + matchsticks[i] <= side_len) {
            //  we take this matchstick in the current side
            if(can_make_sets(can_make_sets, mask | (1 << i), sides_left, curr_sum + matchsticks[i])) {
              cache[mask] = true;
              return true;
            }
          }
        }
        
        cache[mask] = false;
        return false;
      };
      
      return can_make_sets(can_make_sets, 0, 3, 0); //  4th side is implied
    }
};
