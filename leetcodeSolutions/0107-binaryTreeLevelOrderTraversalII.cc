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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(!root) return vector<vector<int>>(0);
        
        vector<vector<int>> ans;
        
        queue<TreeNode*> qu;
        qu.push(root);
        
        while(!qu.empty()){
            int sz = qu.size();
            
            vector<int> currAns;
            while(sz--){
                TreeNode* fr = qu.front();
                qu.pop();
                
                if(fr->left) qu.push(fr->left);
                if(fr->right) qu.push(fr->right);

                currAns.push_back(fr->val);
            }
            
            ans.push_back(currAns);
        }  
        
        reverse(ans.begin(), ans.end());
        
        return ans;
    }
};
