class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int sum = accumulate(nums.begin(), nums.end(), 0);
        
        int conjugate_x = sum - x;
        if(conjugate_x < 0) {
            return -1;    
        }
        
        //  find largest subarray with conjugate_x as sum
        int st = 0, curr_sum = 0, len = INT_MIN;
        for(int ed = 0; ed < n; ++ed) {
            curr_sum += nums[ed];
            while (curr_sum > conjugate_x) {
                curr_sum -= nums[st++];
            }
            if (curr_sum == conjugate_x) {
                len = max(len, ed - st + 1);
            }
        }
        
        return len == INT_MIN ? -1 : n - len;
    }
};
