class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<int> cnt(32, 0);
        for(auto &num : nums){
            for(int bit = 0; bit < 32; ++bit){
              cnt[bit] += num & 1;
              num >>= 1;
            }
        }
        
        int ans = 0;
        for(int i = 0; i < 32; ++i){
            if(cnt[i] % 3 != 0) {
              ans += (1 << i);
            }
        }
        
        return ans;
    }
};
