class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        cin.tie(nullptr)->sync_with_stdio(false);

        sort(points.begin(), points.end(), [](const vector<int> & lhs, const vector<int> & rhs){
            return lhs[0] < rhs[0];
        });

        int ans = 0;
        for(int i = 1; i < points.size(); ++i) {
            ans = max(ans, points[i][0] - points[i - 1][0]);
        }

        return ans;
    }
};
