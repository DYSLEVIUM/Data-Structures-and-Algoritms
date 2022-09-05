class Solution {
public:
    int countArrangement(int n) {
      int cnt = 0;
      auto recur = [&](const auto &recur, const int &idx, const int &mask){
        if(idx == n + 1) {
          ++cnt;
          return ;
        }
        
        for(int i = 1; i < n + 1; ++i) {
          int used = (1 << i) & mask;
          if(!used) {
            if((i % idx == 0) || (idx % i == 0)) {
              recur(recur, idx + 1, mask | (1 << i));
            }
          }
        }
      };
      recur(recur, 1, 0);
      return cnt;
    }
};
