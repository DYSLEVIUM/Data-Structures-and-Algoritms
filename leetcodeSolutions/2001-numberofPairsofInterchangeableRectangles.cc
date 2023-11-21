class Solution {
public:
    long long interchangeableRectangles(vector<vector<int>>& rectangles) {
        cin.tie(nullptr)->sync_with_stdio(false);

        long long ans = 0;
        map<pair<int, int>, int> mp;
        for(const auto & rectangle : rectangles) {
            int width = rectangle[0], height = rectangle[1];
            
            int gcd = __gcd(width, height);
            width /= gcd, height /= gcd;

            pair<int, int> key = { width, height };
            ans += mp[key]++;
        }

        return ans;
    }
};
