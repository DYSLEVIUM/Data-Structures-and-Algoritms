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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root==nullptr) return vector<int>(0);
        
        vector<int> res;
        
        stack<TreeNode*> st;
        
        st.push(root);
        while(!st.empty()){
            TreeNode* tp = st.top();
            
            res.emplace_back(tp->val);
            
            st.pop();
            
            if(tp->right!=nullptr) st.push(tp->right);
            if(tp->left!=nullptr) st.push(tp->left);
        }
        
        return res;
    }
};
