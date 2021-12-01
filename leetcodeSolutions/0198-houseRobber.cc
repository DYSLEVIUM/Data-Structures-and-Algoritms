class Solution {
public:
    int rob(vector<int>& nums) {
        
        if(nums.size()==1) return nums[0];
        
        if(nums.size()==2) return max(nums[0], nums[1]);
        
//         vector<array<int,2>> dp(nums.size());
        
//         //  base cases
//         dp[0][0] = 0;
//         dp[0][1] = nums[0];
        
//         dp[1][0] = dp[0][1];
//         dp[1][1] = nums[1];
        
//         for(int i=2;i<nums.size();++i){
//             dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
//             dp[i][1] = nums[i]+max(dp[i-1][0], dp[i-2][1]);
//         }
        
//         return max(dp[nums.size()-1][0], dp[nums.size()-1][1]);
        
        //  O(1) space
        int prevPrev = nums[0]; //  included
        
        int prevN = nums[0];
        int prev = nums[1];
        
        for(int i=2;i<nums.size();++i){
            int tempPrev = prev;
            int tempPrevN = prevN;
            
            prevN = max(tempPrevN, tempPrev);
            prev = nums[i]+max(tempPrevN, prevPrev);
            
            prevPrev = tempPrev;
        }
        
        return max(prevN, prev);
    }
};
