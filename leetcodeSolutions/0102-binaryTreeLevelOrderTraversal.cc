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
    vector<vector<int>> levelOrder(TreeNode* root) {
      if(!root) return {};
      
      vector<vector<int>> ans;
      queue<TreeNode *> qu;
      qu.push(root);
      while(!qu.empty()) {
        int sz = qu.size();

        vector<int> curr_ans;
        while(sz--) {
          if(qu.front()->left) qu.push(qu.front()->left);
          if(qu.front()->right) qu.push(qu.front()->right);

          curr_ans.push_back(qu.front()->val);
          qu.pop();
        }
        ans.push_back(curr_ans);
      }
      
      return ans;
    }
};
