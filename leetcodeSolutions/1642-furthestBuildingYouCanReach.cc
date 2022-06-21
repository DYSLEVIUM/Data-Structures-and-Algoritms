class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {      
      //  priority_queue
      int n = heights.size();
      priority_queue<int, vector<int>, greater<int>> min_heap;
      for(int i = 1; i < n; ++i) {
        int diff = heights[i] - heights[i - 1];
        if(diff > 0) {
          min_heap.push(diff);
        }
        
        if(min_heap.size() > ladders) {
          bricks -= min_heap.top();
          min_heap.pop();
        }
        
        if(bricks < 0) {
          return i - 1;
        }
      }
      
      return n - 1;
    }
};
