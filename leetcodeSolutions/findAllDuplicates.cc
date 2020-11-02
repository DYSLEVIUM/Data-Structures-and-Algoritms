class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> res;
        
        for(int i=0;i<nums.size();++i){
            if(nums[abs(nums[i])-1]<0)
                res.emplace_back(abs(nums[i]));
            
            nums[abs(nums[i])-1] *= -1;
        }
        
        return res;
    }
};
