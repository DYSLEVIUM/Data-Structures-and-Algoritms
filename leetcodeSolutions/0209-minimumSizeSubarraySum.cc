class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
      int n = nums.size();

      auto get_max_sum = [&nums, &n](int window){
        int sum = 0;
        for(int i = 0; i < window; ++i) sum += nums[i];
        
        int max_window_sum = sum;
        for(int i = window; i < n; ++i){
          sum += nums[i];
          sum -= nums[i - window];
            
          max_window_sum = max(max_window_sum, sum);
        }
          
        return max_window_sum;
      };
      
      int lo = 1, hi = n;
      int ans = 0;
      while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(get_max_sum(mid) >= target) hi = mid - 1, ans = mid;
        else lo = mid + 1;
      }
      cout<<'\n';
      return ans;
    }
};
