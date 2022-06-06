class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        int n = nums.size();
        
        unordered_map<int, int> num_to_idx;
        for(int i = 0; i < n; ++i) {
            num_to_idx[nums[i]] = i;    
        }
        
        for(vector<int> &operation: operations) {
            nums[num_to_idx[operation[0]]] = operation[1];
            num_to_idx[operation[1]] = num_to_idx[operation[0]];
        }
        
        return nums;
    }
};
