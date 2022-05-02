class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        //  using partition
        // partition (nums.begin (), nums.end (), [](const auto &num){ return !(num & 1); });
        // return nums;
        
        int i = 0, j = nums.size() - 1;
        while(i < j) {
            if((nums[i] & 1) > (nums[j] & 1)){
                swap(nums[i], nums[j]);
            }
            
            if(nums[i] % 2 == 0) ++i;
            if(nums[j] & 1) --j;
        }
        
        return nums;
    }
};
