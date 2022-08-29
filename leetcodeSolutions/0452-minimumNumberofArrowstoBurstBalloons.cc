class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
      int n = points.size();
      sort(points.begin(), points.end(), [](const vector<int> &lhs, const vector<int> &rhs){
        if(lhs[1] == rhs[1]) {
          return lhs[0] < rhs[0];
        }
        return lhs[1] < rhs[1];
      });
      
      int cnt = 1;
      int minn = points[0][0], maxx = points[0][1];
      for(auto &point : points) {
        if(point[0] > maxx) {
          ++cnt;
          minn = point[0];
          maxx = point[1];
        }
      }
      
      return cnt;
    }
};
