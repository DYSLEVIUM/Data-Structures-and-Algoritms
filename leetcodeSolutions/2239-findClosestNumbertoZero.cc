class Solution {
public:
    int findClosestNumber(vector<int>& nums) {
      int ans = INT_MAX;
      int dist = INT_MAX;
      for(int &num: nums) {
        if(abs(num) <= dist) {
          if(abs(num) == dist) ans = max(ans, num);
          else ans = num;
          
          dist = abs(num);
        }
      }
      
      return ans;
    }
};
