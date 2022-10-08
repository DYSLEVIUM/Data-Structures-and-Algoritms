class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        // if we consider the case when repeated element is as far as from each other, the only case will be that every subarray of size 2 has the repeated element, so we can just check in the 4 size window if any number is begin repeated;
        for(int j = 1; j < 4; ++j) {
            for(int i = 0; i < nums.size() - j; ++i) {
                if(nums[i] == nums[i + j]) {
                    return nums[i];
                }
            }
        }

        return nums[0];
    }
};
