class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int le = 0, ans = INT_MIN, sum = 0;        
        unordered_set<int> se;
        for(int ri = 0; ri < n; ++ri) {
            while(se.find(nums[ri]) != se.end()) {
                se.erase(nums[le]);
                sum -= nums[le];
                ++le;
            }
            se.insert(nums[ri]);
            sum += nums[ri];
            ans = max(ans, sum);
        }
        
        return ans;
    }
};
