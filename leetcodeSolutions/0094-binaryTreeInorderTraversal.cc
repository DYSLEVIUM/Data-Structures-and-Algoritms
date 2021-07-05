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
    vector<int> inorderTraversal(TreeNode* root) {
        if(root==nullptr) return vector<int>(0);
        
        vector<int> ans;
        
        TreeNode* curr = root;
        stack<TreeNode*> st;
        
        while(curr!=nullptr || !st.empty()){     
            while(curr!=nullptr){
                st.push(curr);
                curr = curr->left;
            }
            
            curr = st.top();
            st.pop();
            
            ans.emplace_back(curr->val);
            
            curr = curr->right;
        }
        
        return ans;
    }
};
