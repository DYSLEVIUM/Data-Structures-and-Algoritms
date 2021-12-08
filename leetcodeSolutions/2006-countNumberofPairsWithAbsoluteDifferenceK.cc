class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        //  i is previous value, j is current value
        //  nums[i] == nums[j] - k;
        //  nums[i] == nums[j] + k;
        
        int ans = 0;
        
        unordered_map<int,int> mp;
        
        for(int i=0;i<nums.size();++i){
            ans += mp[nums[i]+k] + mp[nums[i]-k];
            
            ++mp[nums[i]];
        }
        
        return ans;
    }
};
