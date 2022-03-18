class Solution {
public:
    vector<int> constructRectangle(int area) {
      vector<int> ans(2);
      int diff = INT_MAX;
      for(int i = 1; i * i <= area; ++i){
        if(area % i == 0){
          int other = area / i;
          if(other - i < diff) {
            ans[0] = other, ans[1] = i;
            diff = other - i;
          }
        }
      }
      
      return ans;
    }
};
