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
    vector<int> findFrequentTreeSum(TreeNode* root) {
      unordered_map<int, int> mp;
      int maxx_freq = 0;
      auto recur = [&](const auto &recur, TreeNode * const node){
        if(!node) {
          return 0;
        }
        
        int le = recur(recur, node->left);
        int ri = recur(recur, node->right);
        
        int total = node->val + le + ri;
        
        ++mp[total];
        maxx_freq = max(maxx_freq, mp[total]);
        
        return total;
      };
      recur(recur, root);
      
      vector<int> ans;
      for(auto &[sum, cnt]: mp) {
        if(cnt == maxx_freq) {
          ans.push_back(sum);
        }
      }
      
      return ans;
    }
};
