class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        
        int cnt = 0;
        for(int i = 0; i < n; ++i) {
            int g = nums[i];
            for(int j = i; j < n; ++j) {
                g = __gcd(g, nums[j]);
                cnt += g == k;
            }
        }
        
        return cnt;
    }
};
