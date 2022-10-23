class Solution {
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int n = nums.size();
        auto get_sum = [&](const long long & x){
            long long res = 0;
            for(int i = 0; i < n; ++i) res += 1LL * abs(nums[i] - x) * cost[i];
            return res;
        };
        
        long long ans = 0x3f3f3f3f;

        // this function is convex, so we can apply binary search
        // doing binary search on what the value might be, when the elements will be equal
        long long lo = 0, hi = 1e6;
        while(lo < hi) {
            long long mid = lo + ((hi - lo) >> 1);

            long long y1 = get_sum(mid), y2 = get_sum(mid + 1);
            ans = min(y1, y2);
            
            // we move where the value is decreasing 
            if(y1 < y2) hi = mid;
            else lo = mid + 1;
        }
        
        return ans;
    }
};
