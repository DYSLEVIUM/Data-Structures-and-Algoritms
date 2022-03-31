class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
      auto check = [&nums, &m](const int& x){
        int cnt = 1, sum = 0;
        for(int& num: nums) {
          sum += num;
          
          if(sum > x) {
            ++cnt;
            sum = num;
          }
        }
        
        return cnt <= m;
      };
      
      int lo = *max_element(nums.begin(), nums.end()), hi = accumulate(nums.begin(), nums.end(), 0LL);
      while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(check(mid)) {
          hi = mid - 1;
        } else lo = mid + 1;
      }
      
      return lo;
    }
};
