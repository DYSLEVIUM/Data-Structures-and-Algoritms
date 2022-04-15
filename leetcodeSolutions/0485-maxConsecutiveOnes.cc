class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
      int maxx = 0, cnt = 0;
      for(int &num: nums) {
        ++cnt;
        if(!num) cnt = 0;
        maxx = max(maxx, cnt);
      }
      
      return maxx;
    }
};
