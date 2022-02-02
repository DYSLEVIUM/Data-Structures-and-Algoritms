class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
      unordered_set<int> se;
      for(int i=0;i<n;++i) se.insert(i);

      for(auto& edge: edges) se.erase(edge[1]);
      
      return vector<int>(se.begin(), se.end());
    }
};
