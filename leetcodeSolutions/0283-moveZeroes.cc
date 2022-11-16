class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size(), cnt = 0;
        for(int i = 0; i < n; ++i) {
            if(nums[i]) nums[cnt++] = nums[i];
        }

        for(int i = cnt; i < n; ++i) nums[i] = 0;
    }
};

class Solution1 {
public:
    void moveZeroes(vector<int>& nums) {
      stable_sort(nums.begin(), nums.end(), [](const int &x, const int &y){ return y == 0; });
    }
};
