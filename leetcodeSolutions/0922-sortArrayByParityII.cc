class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        const int n = nums.size();

        vector<int> odd, even;
        for(auto &num : nums) {
            if(num & 1) {
                odd.push_back(num);
            } else {
                even.push_back(num);
            }
        }

        for(int i = 0; i < n; i += 2) {
            nums[i] = even[i >> 1];
            nums[i + 1] = odd[i >> 1];
        }

        return nums;
    }
};
