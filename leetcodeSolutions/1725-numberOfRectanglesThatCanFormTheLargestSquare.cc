class Solution {
public:
    int countGoodRectangles(vector<vector<int>>& rectangles) {
      int maxLen = INT_MIN;
      for(auto& rectangle: rectangles) maxLen = max(maxLen, min(rectangle[0], rectangle[1]));
      
      int ans = 0;
      for(auto& rectangle: rectangles) ans += maxLen == min(rectangle[0], rectangle[1]);
      
      return ans;
    }
};
