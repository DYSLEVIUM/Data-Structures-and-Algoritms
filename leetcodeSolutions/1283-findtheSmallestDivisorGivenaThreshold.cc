class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        auto get_sum = [&](const long long & x){
            long long res = 0;
            for(auto & n : nums) res += ceil(1.0 * n / x);
            return res;
        };

        long long lo = 1, hi = *max_element(nums.begin(), nums.end());
        while(lo < hi) {
            long long mid = lo + ((hi - lo) >> 1);
            long long sum = get_sum(mid);
            if(sum > threshold) lo = mid + 1;
            else hi = mid;
        }

        return lo;
    }
};
