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
    int minCameraCover(TreeNode* root) {
//       int ans = 0;
//       unordered_set<TreeNode *> is_covered;
//       is_covered.insert(nullptr);
      
//       auto contains = [&is_covered](TreeNode * const node){
//         return is_covered.find(node) != is_covered.end();
//       };
//       auto dfs = [&](const auto &dfs, TreeNode * const node, TreeNode * const parent){
//         if(!node) return;
        
//         dfs(dfs, node->left, node);
//         dfs(dfs, node->right, node);
        
//         if(!parent && !contains(node) || !contains(node->left) || !contains(node->right)) {
//           ++ans;
//           is_covered.insert({parent, node, node->left, node->right});
//         }
//       };
//       dfs(dfs, root, nullptr);
      
//       return ans;
      
      //  dp
      /*
        0 -> all nodes below are covered excluding current
        1 -> all nodes below are covered including current, by not adding camera in current node
        2 -> all nodes below are covered including current, by adding camera in current node
      */
      auto dfs = [](const auto &dfs, TreeNode * const node) -> vector<int> {
        if(!node) {
          return { 0, 0, INT_MAX / 2 };
        }
        
        vector<int> le = dfs(dfs, node->left);
        vector<int> ri = dfs(dfs, node->right);
        int mle12 = min(le[1], le[2]);
        int mri12 = min(ri[1], ri[2]);
        
        int d0 = le[1] + ri[1];
        int d1 = min(le[2] + mri12, ri[2] + mle12);
        int d2 = 1 + min(le[0], mle12) + min(ri[0], mri12);
        
        return {d0, d1, d2};
      };
      vector<int> ans = dfs(dfs, root);
      return min(ans[1], ans[2]);
    }
};
