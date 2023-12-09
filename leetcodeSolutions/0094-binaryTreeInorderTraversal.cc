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
// class Solution {
// public:
//     vector<int> inorderTraversal(TreeNode* root) {
//         cin.tie(nullptr)->sync_with_stdio(false);

//         vector<int> ans;

//         TreeNode * curr = root;
//         stack<TreeNode *> st;
//         while(curr || !st.empty()) {
//             while(curr) {
//                 st.push(curr);
//                 curr = curr->left;
//             }

//             curr = st.top();
//             st.pop();

//             ans.push_back(curr->val);

//             curr = curr->right;
//         }

//         return ans;
//     }
// };

// morris traversal
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        cin.tie(nullptr)->sync_with_stdio(false);

        vector<int> ans;

        // threaded binary tree
        TreeNode * curr = root;
        while(curr != nullptr) {
            if(curr->left == nullptr) {
                ans.push_back(curr->val);
                curr = curr->right;
            } else {
                TreeNode * pre = curr->left;
                while(pre->right != nullptr) {
                    pre = pre->right;
                }
                pre->right = curr;
                
                TreeNode * te = curr; // to change the left to null
                curr = curr->left; // update for next iteration

                te->left = nullptr;
            }
        }

        return ans;
    }
};
