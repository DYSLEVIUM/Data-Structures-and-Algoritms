class Solution {
public:
    int maxArea(int h, int w, vector<int>& horizontalCuts, vector<int>& verticalCuts) {
      sort(horizontalCuts.begin(), horizontalCuts.end());
      sort(verticalCuts.begin(), verticalCuts.end());
      
      long long width = max(horizontalCuts[0] - 0, h - horizontalCuts.back());
      long long height = max(verticalCuts[0] - 0, w - verticalCuts.back());
    
      for(int i = 1; i < horizontalCuts.size(); ++i) {
        width = max(width, 1LL * horizontalCuts[i] - horizontalCuts[i - 1]);
      }
      
      for(int i = 1; i < verticalCuts.size(); ++i) {
        height = max(height, 1LL * verticalCuts[i] - verticalCuts[i - 1]);
      }
      
      const int MOD = 1e9 + 7;
      
      return ((width % MOD) * (height % MOD)) % MOD;
    }
};
