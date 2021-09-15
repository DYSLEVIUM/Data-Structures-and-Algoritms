class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        int ans = 0;
        
        for(int i = 0; i + 1 < nums.size(); i += 2) ans += min(nums[i], nums[i + 1]);
        
        return ans;
    }
};
