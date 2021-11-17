class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorVal = 0;
        
        for(auto num: nums) xorVal ^= num;
        
        return xorVal;
    }
};
