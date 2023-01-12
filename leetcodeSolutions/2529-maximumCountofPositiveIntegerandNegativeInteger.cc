class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int sz = nums.size();

        int ne = upper_bound(nums.begin(), nums.end(), -1) - nums.begin();
        int po = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        
        return max(ne, sz - po);
    }
};
