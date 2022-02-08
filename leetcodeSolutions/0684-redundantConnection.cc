class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      int n = edges.size();
      
      //  disjoint set union
      vector<int> parent(n + 1);
      vector<int> rank(n + 1);
      auto find_parent = [&parent](const auto& find_parent, const int& node)->int{
        return parent[node] = (parent[node] == node ? node : find_parent(find_parent, parent[node])); //  path compression
      };
      
      auto merge = [&parent, &rank, &find_parent](int node_1, int node_2){
        node_1 = find_parent(find_parent, node_1);
        node_2 = find_parent(find_parent, node_2);
        
        if(node_1 == node_2) return;
        
        if(rank[node_1] == rank[node_2]) ++rank[node_1];
        
        //  greater rank will be the parent, to reduce the tree traversal which will be inverse-ackerman function on average
        rank[node_1] < rank[node_2] ? parent[node_1] = node_2 : parent[node_2] = node_1;
      };
      
      //  all nodes are initially their own parent
      iota(parent.begin(), parent.end(), 0);
    
      vector<int> ans(1);
      for(auto& edge: edges){
        if(find_parent(find_parent, edge[0]) == find_parent(find_parent, edge[1])) ans = {edge[0], edge[1]};
        else merge(edge[0], edge[1]);
      }
      
      return ans;
    }
};
