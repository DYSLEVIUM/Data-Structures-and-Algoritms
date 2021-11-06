class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& points) {
        sort(points.begin(),points.end(), [](const vector<int>& a, const vector<int>& b){
            if(a[0]==b[0]) return a[1]<b[1];
            return a[0]<b[0];
        });
        
        int maxHoriDist = INT_MIN;
        for(int i=0;i<points.size()-1;++i) maxHoriDist = max(maxHoriDist, points[i+1][0]-points[i][0]);
        
        return maxHoriDist;
    }
};
