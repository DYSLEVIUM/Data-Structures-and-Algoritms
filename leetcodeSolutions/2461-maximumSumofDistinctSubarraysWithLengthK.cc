class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        
        unordered_map<int, int> mp;
        long long maxx = 0, curr = 0;
        for(int i = 0; i < min(n, k - 1); ++i) ++mp[nums[i]], curr += nums[i];
        
        for(int i = k - 1; i < n; ++i) {
            ++mp[nums[i]], curr += nums[i];
            if(mp.size() == k) maxx = max(maxx, curr);
            
            --mp[nums[i - k + 1]], curr -= nums[i - k + 1];
            if(!mp[nums[i - k + 1]]) mp.erase(nums[i - k + 1]);
        }
        
        return maxx;
    }
};
