class Solution {
public:
    vector<int> countBits(int n) {
      vector<int> ans(n + 1);
      for(int i = 0 ; i < n + 1; ++i) ans[i] = i & 1 ? ans[i / 2] + 1 : ans[i / 2];
      
      return ans;
    }
};
