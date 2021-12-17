class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        
        int mini = INT_MAX, maxi = INT_MIN;
        int mini_idx = -1, maxi_idx = -1;
        
        for(int i=0;i<n;++i){
            if(nums[i]<mini){
                mini = nums[i];
                mini_idx = i;
            }
            
            if(nums[i]>maxi){
                maxi = nums[i];
                maxi_idx = i;
            }
        }
        
        return min({max(maxi_idx, mini_idx)+1, 
                    n - min(maxi_idx, mini_idx), 
                    min(maxi_idx, mini_idx)+1 + n - max(maxi_idx, mini_idx)
                });
    }
};
