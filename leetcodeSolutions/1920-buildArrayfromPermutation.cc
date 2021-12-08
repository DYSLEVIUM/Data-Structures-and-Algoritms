class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        //  we will modify the original array by storing two information in it, i.e., turn it into a = qb + r
        int q = nums.size();
        
        for(int i=0;i<nums.size();++i) {
            //  we can get the old value with nums[i]%q and the new value with nums[i]/q;
            int r = nums[i];    
            
            int b = nums[nums[i]] % q;
            nums[i] = q*b + r;
        }
        
        for(int i=0;i<nums.size();++i) nums[i] /= q;
        
        return nums;
    }
};
