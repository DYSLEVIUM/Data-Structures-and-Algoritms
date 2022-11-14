class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int total = accumulate(nums.begin(), nums.end(), 0);
        for(int i = 0; i < nums.size(); ++i) {
            int le = sum, ri = total - sum - nums[i];
            if(le == ri) return i;
            sum += nums[i];
        }
        return -1;
    }
};
