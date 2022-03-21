class Solution {
public:
    vector<int> sumZero(int n) {
      vector<int> ans(n);
      for(int i = 0; i < n / 2; ++i) ans[i] = i + 1, ans[n - i - 1] = -(i + 1);
      if(n & 1) ans[n / 2] = 0;
      
      return ans;
    }
};
