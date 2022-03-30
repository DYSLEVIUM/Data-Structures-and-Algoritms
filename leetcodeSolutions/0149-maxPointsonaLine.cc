class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
      int n = points.size();
      
      auto gcd = [](int a, int b){
        while (b) {
          a = a % b;
          swap(a, b);
        }
        return a;
      };
      
      int ans = 0;
      for(int i = 0; i < n; ++i) {
        map<pair<int, int>, int> mp;
        int duplicate = 1;
        for(int j = i + 1; j < n; ++j) {
          if(points[i][0] == points[j][0] && points[i][1] == points[j][1]) {
            ++duplicate;
          } else {
            int dx = points[j][0] - points[i][0], dy = points[j][1] - points[i][1];
            
            int g = gcd(dx, dy);
            dx /= g, dy /= g;
            
            ++mp[{dx, dy}];
          }
        }
          ans = max(ans, duplicate);
          for (auto& p : mp) ans = max(ans, p.second + duplicate);
      }
      
      return ans;
    }
};
