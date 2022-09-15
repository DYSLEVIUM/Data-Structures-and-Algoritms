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
    int pseudoPalindromicPaths (TreeNode* root) {
      int cnt = 0;
      auto check_pali = [](const unordered_map<int, int> &fa, const int &n){
        int odd_cnt = 0;
        
        for(auto &[num, cnt] : fa) {
          odd_cnt += cnt & 1;
        }
        
        if(n & 1) {
          if(odd_cnt != 1) {
            return false;          
          }
        } else {
          if(odd_cnt) {
            return false;
          }
        }
        return true;
      };
      
      auto recur = [&](const auto &recur, TreeNode * const &node, unordered_map<int, int> &curr_stack, const int &depth) {
        if(!node) {
          return ;
        }
        
        int new_depth = depth + 1;
        
        ++curr_stack[node->val];
        
        // call only one side
        if(!node->left && !node->right) {
          cnt += check_pali(curr_stack, new_depth);
        } else {
          recur(recur, node->left, curr_stack, new_depth);
          recur(recur, node->right, curr_stack, new_depth);
        }
        
        --curr_stack[node->val];
      };
      unordered_map<int, int> curr_stack;
      recur(recur, root, curr_stack, 0);
      
      return cnt;
    }
};
