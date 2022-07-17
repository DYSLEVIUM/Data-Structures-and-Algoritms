/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        const int MAXN = 1e5 + 1;
        const int LOGN = log2(ceil(1.0 * MAXN));
        
        TreeNode *invalid_node = new TreeNode(-1);
        
        unordered_map<TreeNode *, int> depth;
        map<TreeNode *, vector<TreeNode *>> node_to_ancestor;
        auto dfs = [&](const auto &dfs, TreeNode * const node, TreeNode * const parent) -> void {
            node_to_ancestor[node] = vector<TreeNode *>(LOGN, invalid_node);
            node_to_ancestor[node][0] = parent;
            depth[node] = 1 + depth[parent];
            
            for(int i = 1; i < LOGN; ++i) {
                if(node_to_ancestor[node][i - 1] == invalid_node) {
                    break;
                }
                node_to_ancestor[node][i] = node_to_ancestor[node_to_ancestor[node][i - 1]][i - 1];
            }
            
            if(node->left) { 
                dfs(dfs, node->left, node);
            }
            
            if(node->right) {
                dfs(dfs, node->right, node);
            }
        };
        dfs(dfs, root, invalid_node);
        
        for(auto [node, ancestor]: node_to_ancestor){
            cout << node->val << ": ";
            for(int i = 0; i < LOGN; ++i) {
                if(ancestor[i] == invalid_node) {
                    cout << "-1, ";
                } else {
                    cout << ancestor[i]->val << ", ";
                }
            }
            cout << '\n';
        }
        
        if(depth[p] < depth[q]) {
            swap(p, q);
        }
        
        //  linear solution
//         {
//             while(depth[p] > depth[q]) {
//                 //  making the distance to common ancestor equal
//                 p = node_to_ancestor[p][0];
//             }

//             while(p != q) {
//                 p = node_to_ancestor[p][0];
//                 q = node_to_ancestor[q][0];
//             }
//         }
        
        //  logn for every query, but here it is only one query
        //  using binary lifting
        {
            int k = depth[p] - depth[q];
            
            //  make p's distance equal to q's distance
            for(int i = 0; i < LOGN; ++i) {
                if(k & (1 << i)) {
                    p = node_to_ancestor[p][i];
                }
            }
            
            //  the edge case when q is the common ancestor itself, i.e (p == q), we simply return p or q
            
            if(p != q) {
                //  making smaller steps when ancestors dont' match up where the ancestors don't match up (higher ancestors will match)
                for(int i = LOGN - 1; i >= 0; --i) {
                    if(node_to_ancestor[p][i] != node_to_ancestor[q][i]) {
                        p = node_to_ancestor[p][i];
                        q = node_to_ancestor[q][i];
                    }
                }
                
                //  at this point, p and q both are children of the ancestor, so we just return the parent
                p = node_to_ancestor[p][0];
                q = node_to_ancestor[q][0];
            }
        }
        
        delete invalid_node;
        invalid_code = nullptr;
        
        return p;
    }
};
