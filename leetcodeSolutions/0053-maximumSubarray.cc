class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        static constexpr int INF = 0x3f3f3f3f;
        int sum = -INF, best = -INF; 
        for(int & num : nums) {
            sum = max(sum + num, num);
            best = max(best, sum);
        }
        return best;
    }
};
