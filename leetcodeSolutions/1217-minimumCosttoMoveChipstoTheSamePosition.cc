class Solution {
public:
    int minCostToMoveChips(vector<int>& position) {
      int even_cnt = 0, odd_cnt = 0;
      
      for(int i = 0; i < position.size(); ++i) {
        if(position[i] & 1) ++odd_cnt;
        else ++even_cnt;
      }
      
      return min(even_cnt, odd_cnt);
    }
};
