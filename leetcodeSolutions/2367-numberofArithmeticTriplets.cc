class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt = 0;
        for(int i = 0; i < nums.size(); ++i) {
            cnt += binary_search(nums.begin(), nums.begin() + i, nums[i] - diff) 
                    && binary_search(nums.begin() + i + 1, nums.end(), nums[i] + diff);
        }

        return cnt;
    }
};
