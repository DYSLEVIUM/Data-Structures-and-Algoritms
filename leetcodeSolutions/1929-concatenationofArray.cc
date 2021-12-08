class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int sz = nums.size();
        
        for(int i=0;i<sz;++i) nums.push_back(nums[i]);
        
        return nums;
    }
};
