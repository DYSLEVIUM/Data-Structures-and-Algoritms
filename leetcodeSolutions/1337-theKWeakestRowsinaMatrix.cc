class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
      int rows = mat.size(), cols = mat[0].size();
      
      priority_queue<pair<int, int>> max_heap;
      for(int row = 0; row < rows; ++row) {
        int sum = 0;
        for(int col = 0; col < cols; ++col) {
          if(!mat[row][col]) break;
          ++sum;
        }
        
        max_heap.push({sum, row});
        if(max_heap.size() > k) max_heap.pop();
      }
      
      vector<int> ans;
      while(!max_heap.empty()) {
        ans.push_back(max_heap.top().second);
        max_heap.pop();
      }
      reverse(ans.begin(), ans.end());
      
      return ans;
    }
};
