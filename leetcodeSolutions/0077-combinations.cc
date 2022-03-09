class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
      vector<vector<int>> combs;
      
      auto get_ans = [&n, &combs](const auto& get_ans, const int& idx, const int& curr_k, vector<int>& curr_ans) {
        if(curr_k == 0) {
          combs.push_back(curr_ans);
          return;
        }
        
        for(int i = idx; i <= n; ++i) {
          curr_ans.push_back(i);
          get_ans(get_ans, i + 1, curr_k - 1, curr_ans);
          curr_ans.pop_back();
        }
      };
      vector<int> dummy = {};
      get_ans(get_ans, 1, k, dummy);
      
      return combs;
    }
};
