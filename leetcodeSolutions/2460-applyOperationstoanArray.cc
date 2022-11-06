class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n - 1; ++i) {
            if(nums[i] == nums[i + 1]) {
                nums[i] <<= 1;
                nums[i + 1] = 0;
            }
        }
      
        stable_sort(nums.begin(), nums.end(), [](const int & x, const int & y){
            if(x == 0 || y == 0) {
                if(x == 0) return false;
                else return true;
            }

            return false;
        });
      
        return nums;
    }
};
