class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), [](const vector<int> & lhs, const vector<int> & rhs){
            return lhs[1] < rhs[1];
        });

        int prev = 0, ans = 0;
        for(int i = 1; i < intervals.size(); ++i) {
            if(intervals[prev][1] > intervals[i][0]) ++ans;
            else prev = i;
        }
        return ans;
    }
};
