class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
        auto get_sum = [](int x){
            int ans = 0;
            while(x) {
                ans += x % 10;
                x /= 10;
            }
            return ans;
        };

        unordered_map<int, int> mp;
        int maxx = INT_MIN;
        for(int i = lowLimit; i <= highLimit; ++i) {
            maxx = max(maxx, ++mp[get_sum(i)]);
        }

        return maxx;
    }
};
