class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> ans;
        
        for(int i=0;i<intervals.size();++i){
            int start = intervals[i][0];
            int end = intervals[i][1];

            int j = i+1;
            while(j<intervals.size() && intervals[j][0]<=end){
                end = max(end, intervals[j][1]);    //  if we get better end, we update it with the current end, so as to minimize the amount of intervals
                ++j;
            }
            
            end = max(end, intervals[j-1][1]);  //  doing max for [[1, 4],[2, 3]]
            i = j-1;
            ans.emplace_back(vector<int>({start, end}));
        }
        
        return ans;
    }
};
