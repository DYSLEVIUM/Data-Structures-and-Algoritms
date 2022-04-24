class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        
        vector<int> prefix_max(n);
        prefix_max[0] = height[0];
        for(int i = 1; i < n; ++i) {
            prefix_max[i] = max(prefix_max[i - 1], height[i]);
        }
        
        vector<int> suffix_max(n);
        suffix_max[n - 1] = height[n - 1];
        for(int i = n - 2; i >= 0; --i) {
            suffix_max[i] = max(suffix_max[i + 1], height[i]);
        }
        
        int total_rain_water = 0;
        for(int i = 0; i < n; ++i) {
            int left_max = i - 1 >= 0 ? prefix_max[i - 1] : 0;
            int right_max = i + 1 < n ? suffix_max[i + 1] : 0;
            
            total_rain_water += (min(left_max, right_max) - height[i] > 0 ? min(left_max, right_max) - height[i] : 0);                
        }
        
        return total_rain_water;
    }
};
