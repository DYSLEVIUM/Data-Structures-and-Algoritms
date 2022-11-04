class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> se;
        for(int i = 0; i < nums.size() - 1; ++i) {
            if(se.count(nums[i] + nums[i + 1])) return true;
            se.insert(nums[i] + nums[i + 1]);
        }

        return false;
    }
};
