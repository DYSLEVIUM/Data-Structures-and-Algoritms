class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int isLessThanTarget = 0;
        int totalTargetPresent = 0;
                
        for(int i=0;i<nums.size();++i){
            if(nums[i]==target) ++totalTargetPresent;
            else if(nums[i]<target) ++isLessThanTarget;
        }
        
        vector<int> ans;

        for(int i=0;i<totalTargetPresent;++i) ans.push_back(isLessThanTarget++);
        
        return ans;
    }
};
