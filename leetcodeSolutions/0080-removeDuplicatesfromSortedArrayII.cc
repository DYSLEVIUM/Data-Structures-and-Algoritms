class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
      int n = nums.size();
      int k = 1;
      for(int i = 1; i < n; ++i) {
        if(nums[i] != INT_MAX && nums[i] == nums[i - 1]) {
          int j = i + 1;
          while(j < n && nums[j] == nums[i]){
            nums[j++] = INT_MAX;
          }
        }
        
        k += nums[i] != INT_MAX;
      }
      
      int mx_ptr = 0, not_mx_ptr = 0;
      while(mx_ptr < n && not_mx_ptr < n) {
        while(mx_ptr < n && nums[mx_ptr] != INT_MAX) ++mx_ptr;
        
        not_mx_ptr = mx_ptr;  //  always move the right elements
        while(not_mx_ptr < n && nums[not_mx_ptr] == INT_MAX) ++not_mx_ptr;
        
        if(mx_ptr >= n || not_mx_ptr >= n) break;
        
        swap(nums[mx_ptr++], nums[not_mx_ptr++]);
      }
      
      return k;
    }
};
