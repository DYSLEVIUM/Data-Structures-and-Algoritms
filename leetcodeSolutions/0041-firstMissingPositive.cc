class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        
        //  we repetedly put the numbers in their correct place
        for(int i=0;i<nums.size();++i)
            while(nums[i]>0 && nums[i]<=nums.size() && nums[i]!=nums[nums[i]-1]) 
                swap(nums[i], nums[nums[i]-1]);
        
        //  check for the least number that isn;t in its correct position
        for(int i=0;i<nums.size();++i)
            if(nums[i]!=i+1) 
                return i+1;
        
        //  if all the numbers are in their correct postion, n+1 will be the first missing number
        return nums.size()+1;
    }
};
