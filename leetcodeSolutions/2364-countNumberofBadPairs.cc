class Solution {
public:
    long long countBadPairs(vector<int>& nums) {
        int n = nums.size();

        long long ans = 0;
        unordered_map<int, int> mp;
        for(int i = 0; i < n; ++i) {
            // i is the total elements till now
            ans += i - mp[i - nums[i]];
            
            // adding new element
            ++mp[i - nums[i]];
        }
        
        return ans;
    }
};
