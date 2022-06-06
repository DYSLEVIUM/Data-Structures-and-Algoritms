class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        
        int cnt = 0;
        int minn = INT_MAX, maxx = INT_MIN;
        for(int i = 0; i < n; ++i) {
            maxx = max(maxx, nums[i]);
            minn = min(minn, nums[i]);
            
            if(maxx - minn > k) {
                ++cnt;
                maxx = minn = nums[i];
            }
        }
        
        return cnt + 1;
    }
};
