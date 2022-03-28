class Solution {
public:
    int findPeakElement(vector<int>& nums) {
      int n = nums.size();
      
      if(n == 1) return 0;
      
      auto check = [&nums, &n](const int& x){
        if(x - 1 < 0) {
          if(nums[x] > nums[x + 1]) return true;
          return false;
        }
        
        if(x + 1 >= n) {
          if(nums[x] > nums[x - 1]) return true;
          return false;
        }
        
        return (nums[x] > nums[x - 1] && nums[x] > nums[x + 1]);
      };
      
      int lo = 0, hi = n - 1;
      while(lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        
        if(check(mid)) return mid;
        else if(mid - 1 >=0 && nums[mid - 1] > nums[mid]) hi = mid - 1;
        else if(mid + 1 < n && nums[mid + 1] > nums[mid]) lo = mid + 1;
      }
      
      return -1;
    }
};
