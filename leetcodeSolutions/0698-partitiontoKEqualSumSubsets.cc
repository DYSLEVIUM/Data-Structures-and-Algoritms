class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
      int n = nums.size();
      
      int total = accumulate(nums.begin(), nums.end(), 0);
      int total_in_set = total / k;
      
      //  impossible solution
      if(n < k || total_in_set * k != total || *max_element(nums.begin(), nums.end()) > total_in_set) {
        return false;
      }
      
      vector<int> cache(1 << n, -1);
      auto can_make_set = [&](const auto &can_make_set, const int &sets_left, const int &mask, const int &curr_sum){
        if(!sets_left) {
          return true;
        }
        if(curr_sum == total_in_set) {
          return can_make_set(can_make_set, sets_left - 1, mask, 0);
        }
        
        if(cache[mask] != -1) {
          return !!cache[mask];
        }
        
        for(int i = 0; i < n; ++i) {
          //  if the ith number has not been used
          if((mask & (1 << i)) == 0 && curr_sum + nums[i] <= total_in_set) {
            if(can_make_set(can_make_set, sets_left, mask | (1 << i), curr_sum + nums[i])) {
              cache[mask] = true;
              return true;
            } 
          }
        }
        
        cache[mask] = false;
        return false;
      };   
    
      return can_make_set(can_make_set, k - 1, 0, 0); //  last set is implied
    }
};
