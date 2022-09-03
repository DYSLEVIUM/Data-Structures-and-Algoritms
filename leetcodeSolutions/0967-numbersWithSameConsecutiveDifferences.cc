class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
      vector<int> ans;
      auto get_num = [&](const auto &get_num, const int &num, const int &used){
        if(used == n) {
          ans.push_back(num);
          return ;
        }
        
        int last = num % 10;
        if(last + k < 10) {
          get_num(get_num, num * 10 + (last + k), used + 1);
        }
        
        if(k && last - k >= 0) {
          get_num(get_num, num * 10 + (last - k), used + 1);
        }
      };
      
      for(int i = 1; i < 10; ++i) {
        get_num(get_num, i, 1);
      }
      
      return ans;
    }
};
