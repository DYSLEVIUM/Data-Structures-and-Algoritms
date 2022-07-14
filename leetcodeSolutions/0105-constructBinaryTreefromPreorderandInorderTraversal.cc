/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
      int sz = preorder.size();
      
      unordered_map<int, int> pos;
      for(int i = 0; i < sz; ++i) {
        pos[inorder[i]] = i;
      }
      
      auto make_tree = [&](const auto &make_tree, int &pr_ptr, const int &in_l, const int &in_r) -> TreeNode* {
        if(pr_ptr == sz || in_l > in_r) {
          return nullptr;
        }
        
        int node_val = preorder[pr_ptr];
        ++pr_ptr;
        
        TreeNode *node = new TreeNode(node_val);
        node->left = make_tree(make_tree, pr_ptr, in_l, pos[node_val] - 1);
        node->right = make_tree(make_tree, pr_ptr, pos[node_val] + 1, in_r);
        
        return node;
      };
      
      int pr_ptr = 0;
      return make_tree(make_tree, pr_ptr, 0, sz - 1);
    }
};
