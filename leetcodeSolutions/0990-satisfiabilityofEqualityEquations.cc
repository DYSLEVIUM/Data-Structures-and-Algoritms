constexpr int CHAR_SET = 26;

class DSU {
public:
  explicit DSU() {
    m_parent.resize(CHAR_SET);
    iota(m_parent.begin(), m_parent.end(), 0);

    m_rank.resize(CHAR_SET);
  }
  
  void merge(int node1,int node2) {
    node1 = find(node1);
    node2 = find(node2);
    
    if(node1 == node2) {
      return ;
    }
    
    if(m_rank[node1] == m_rank[node2]) {
      ++m_rank[node1];
    }

    m_rank[node1] < m_rank[node2] ? m_parent[node1] = node2 : m_parent[node2] = node1;
  }
  
  const int &find(const int& node) {
    return m_parent[node] = m_parent[node] == node ? node : find(m_parent[node]);
  }
private:
  vector<int> m_parent;
  vector<int> m_rank;
};

class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
      DSU dsu;
      for(auto &equation : equations) {
        int node1 = equation[0] - 'a';
        int node2 = equation[3] - 'a';
        
        char op = equation[1];
        
        if(op == '=') {
          dsu.merge(node1, node2);
        }
      }
      
      for(auto &equation : equations) {
        int node1 = equation[0] - 'a';
        int node2 = equation[3] - 'a';
        
        char op = equation[1];
        
        if(op == '!' && dsu.find(node1) == dsu.find(node2)) {
          return false;
        }
      }
      
      return true;
    }
};

/*
["c==c","f!=a","f==b","b==c"]
["a==b","b!=a"]
["b==a","a==b"]
["b==a","a==b","c!=b"]
["b==a","a==b","c==b"]
*/
