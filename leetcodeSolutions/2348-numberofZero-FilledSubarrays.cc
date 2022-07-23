class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        
        long long cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(!nums[i]) {
                int j = i;
                
                while(j < n && !nums[j]) {
                    ++j;
                }
                --j;
                
                int len = j - i + 1;
                cnt += 1LL * len * (len + 1) / 2;
                
                i = j;
            }
        }
        
        return cnt;
    }
};
