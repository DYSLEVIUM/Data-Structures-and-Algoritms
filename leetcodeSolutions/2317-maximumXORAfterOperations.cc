class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        return accumulate(nums.begin(), nums.end(), 0, bit_or());
    }
};
