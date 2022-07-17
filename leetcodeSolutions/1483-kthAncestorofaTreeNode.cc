class TreeAncestor {
public:
    TreeAncestor(int n, vector<int>& parent) {
        m_logn = ceil(log2(1.0 * n));
        m_node_to_ancestor = vector<vector<int>>(n, vector<int>(m_logn, -1));

        //  here we are assuming parent[i] < i, because we compute all the nodes from 0 to n - 1, if this is not the case, we can simply swap the for loops, but we need extra pass for assigning parent, essentially, we compute all the 2^0 ancestors of all the nodes then 2^1 ancestors of all the nodes, and so on
        //  binary lifting
//         for(int i = 0; i < n; ++i) {
//             m_node_to_ancestor[i][0] = parent[i];
            
//             //  2^jth ancestor of ith node
//             for(int j = 1; j < m_logn; ++j) {
//                 if(m_node_to_ancestor[i][j - 1] == -1) {
//                     m_node_to_ancestor[i][j] = -1;    
//                 } else {
//                     m_node_to_ancestor[i][j] = m_node_to_ancestor[m_node_to_ancestor[i][j - 1]][j - 1];
//                 }
//             }
//         }
        
        
        //  if order is messed up
        for(int i = 0; i < n; ++i) {
            m_node_to_ancestor[i][0] = parent[i];
        }
        for(int j = 1; j < m_logn; ++j) {
            for(int i = 0; i < n; ++i) {
                if(m_node_to_ancestor[i][j - 1] == -1) {
                    m_node_to_ancestor[i][j] = -1;    
                } else {
                    m_node_to_ancestor[i][j] = m_node_to_ancestor[m_node_to_ancestor[i][j - 1]][j - 1];
                }
            }
        }
    }
    
    int getKthAncestor(int node, int k) {
        if(k >= (1 << m_logn)) {
            return -1;
        }
        
        for(int j = 0; j < m_logn; ++j) {
            if(node == -1) {
                break;
            }
            
            //  if the jth bit is set
            if(k & (1 << j)) {
                node = m_node_to_ancestor[node][j];
            }
        }
        return node;
    }
private:
    vector<vector<int>> m_node_to_ancestor;
    int m_logn;
};

/**
 * Your TreeAncestor object will be instantiated and called as such:
 * TreeAncestor* obj = new TreeAncestor(n, parent);
 * int param_1 = obj->getKthAncestor(node,k);
 */
