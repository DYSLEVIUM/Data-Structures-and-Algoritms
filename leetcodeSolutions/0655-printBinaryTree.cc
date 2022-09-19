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
    vector<vector<string>> printTree(TreeNode* root) {
      auto get_height = [&](const auto &get_height, TreeNode * const node){
        if(!node) {
          return 0;
        }
        
        int le = get_height(get_height, node->left);
        int ri = get_height(get_height, node->right);
        
        return 1 + max(le, ri);
      };
      
      int height = get_height(get_height, root);
      int rows = height, cols = (1 << height) - 1;
      
      vector<vector<string>> ans(rows, vector<string>(cols));
      auto recur = [&](const auto &recur, const int &curr_row, TreeNode * const &node, const int &le, const int &ri){
        if(!node) {
          return ;
        }
        
        int mid = le + (ri - le + 1) / 2;
        ans[curr_row][mid] = to_string(node->val);
        
        recur(recur, curr_row + 1, node->left, le, mid - 1);
        recur(recur, curr_row + 1, node->right, mid + 1, ri);
      };
      recur(recur, 0, root, 0, cols - 1);
      
      return ans;
    }
};
