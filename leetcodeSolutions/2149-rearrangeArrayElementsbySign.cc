class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
      vector<int> res;
      
      int n = nums.size();
      int p_ptr=0, n_ptr=0;
      while(max(p_ptr, n_ptr) < n){
        while(nums[p_ptr++]<0);
        while(nums[n_ptr++]>=0);

        res.push_back(nums[p_ptr-1]);
        res.push_back(nums[n_ptr-1]);
      }
      
      return res;
    }
};
