class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
      int ans = 0;
      int n = nums.size();
      
      int other_ptr = 0;
      for(int i=0;i<n;++i){
        if(nums[i]!=val){
          nums[other_ptr++] = nums[i];
          ++ans;
        }
      }
      
      return ans;
    }
};
