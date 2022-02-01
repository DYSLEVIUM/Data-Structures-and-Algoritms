class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
      int n = nums.size();
      sort(nums.begin(), nums.end());
      
      int ans = nums[0] + nums[1] + nums[3];
      for(int i=0;i<n-2;++i){
        int j = i+1;
        int k = n-1;
        
        while(j < k){
          int curr_ans = nums[i] + nums[j] + nums[k];
          
          if(abs(curr_ans-target)< abs(ans-target)) ans = curr_ans;
          
          if(curr_ans > target) --k;
          else ++j;
        }
      }
      
      return ans;
    }
};
