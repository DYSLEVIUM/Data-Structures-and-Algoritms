class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> se(nums.begin(), nums.end());
        while(se.count(original)) {
            original <<= 1;
        }

        return original;
    }
};
