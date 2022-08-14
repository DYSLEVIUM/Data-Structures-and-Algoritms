class Solution {
public:
    int maximumTop(vector<int>& nums, int k) {
        int n = nums.size();
        if(k == 1 && n == 1) {
            return -1;
        }
        
        if(n == 1) {
            if(k & 1) {
                return -1;
            }
            
            return nums[0];
        }
        
        int maxx = INT_MIN;
        
        // remove all the k - 1 elements
        for(int i = 0; i < min(n, k - 1); ++i) {
            maxx = max(maxx, nums[i]);
        }
        
        // there is no way to take nums[k - 1]
        
        maxx = max(maxx, n > k ? nums[k] : INT_MIN);
        
        return maxx;
    }
};
