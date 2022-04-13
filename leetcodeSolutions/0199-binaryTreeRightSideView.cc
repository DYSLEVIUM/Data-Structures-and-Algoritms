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
    vector<int> rightSideView(TreeNode* root) {
      vector<int> ans;
      if(!root) return ans;
      
      queue<TreeNode *> qu;
      qu.push(root);
      while(!qu.empty()) {
        int sz = qu.size();
        while(sz--) {
          TreeNode *fr = qu.front();
          qu.pop();
          if(sz == 0) {
            ans.push_back(fr->val);
          }
          if(fr->left) qu.push(fr->left);
          if(fr->right) qu.push(fr->right);
        }
      }
      
      return ans;
    }
};
