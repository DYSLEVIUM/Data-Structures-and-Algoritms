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
    int widthOfBinaryTree(TreeNode* root) {
      if(!root) return 0;

      //  simple bfs with offest (we store the offset as 2*i for left and 2*i+1 for right assuming the root starts at 0);
      long long ans = INT_MIN;
      queue<pair<TreeNode*, long long>> qu;
      qu.push({root, 0});
      while(!qu.empty()){
        int curr_size = qu.size();
        long long left_end = qu.front().second;
        long long right_end = qu.front().second;
        while(curr_size--){
          auto front = qu.front();
          qu.pop();
          
          right_end = front.second;
          
          if(front.first->left) qu.push({front.first->left, 2 * (right_end - left_end) + 1});
          if(front.first->right) qu.push({front.first->right, 2 * (right_end - left_end) + 2});
        }
        
        ans = max(ans, right_end - left_end + 1);
      }
      
      return ans;
    }
};
