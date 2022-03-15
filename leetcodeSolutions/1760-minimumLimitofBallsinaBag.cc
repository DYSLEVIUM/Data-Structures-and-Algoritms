class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
      int n = nums.size();
      auto get_operations = [&nums, &n](const int& x){
        int ops = 0;
        for(int i = 0; i < n; ++i){
          ops += (nums[i] - 1) / x; 
        }
        
        return ops;
      };      
      
      int lo = 1, hi = INT_MAX;
      while(lo < hi){
        int mid = lo + (hi - lo) / 2;
        
        if(get_operations(mid) <= maxOperations) hi = mid;
        else lo = mid + 1;
      }
      
      return lo;
    }
};
