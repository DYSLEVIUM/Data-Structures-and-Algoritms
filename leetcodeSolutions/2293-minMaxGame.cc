class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        int n = nums.size();
        for(int i = n; i > 1; i -= (i >> 1)) {
            for(int j = 0; j < i/2; ++j) {
                int temp;
                
                if(j & 1) {
                    temp = max(nums[2 * j], nums[2 * j + 1]);
                } else {
                    temp = min(nums[2 * j], nums[2 * j + 1]);
                }
                
                nums[j] = temp;
            }
        }
        
        return nums[0];
    }
};
