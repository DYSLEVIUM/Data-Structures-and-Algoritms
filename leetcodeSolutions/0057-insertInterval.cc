class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
      int n = intervals.size();
      
      vector<vector<int>> ans;
      int ptr = 0;
      //  insert all elements that come before
      while(ptr < n && intervals[ptr][1] < newInterval[0]){
        ans.push_back(intervals[ptr++]);
      }
      
      //  overlapping intervals
      while(ptr < n && newInterval[1] >= intervals[ptr][0]){
        newInterval[0] = min(newInterval[0], intervals[ptr][0]);
        newInterval[1] = max(newInterval[1], intervals[ptr][1]);
        ++ptr;
      }
      ans.push_back(newInterval);
      
      //  insert remaining elements
      while(ptr < n){
        ans.push_back(intervals[ptr++]);
      }
      
      return ans;
    }
};
