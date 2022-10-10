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
    TreeNode* trimBST(TreeNode * &root, const int &low, const int &high) {
        if(!root) {
            return nullptr;
        }

        root->left = trimBST(root->left, low, high);
        root->right = trimBST(root->right, low, high);

        if(low <= root->val && root->val <= high) {
            return root;
        }

        if(!root->left && !root->right) {
            return root = nullptr;
        } else if(root->left && root->right) {
            TreeNode *temp;
            if(temp->left) {
                temp = temp->left;
                // inorder predecessor
                while(temp->right) {
                    temp = temp->right;
                }
            } else {
                temp = temp->right;
                // inorder successor
                while(temp->left) {
                    temp = temp->left;
                }
            }
            swap(root->val, temp->val);
            trimBST(temp, low, high);
        } else {
            if(root->left) {
                return root->left;
            } else {
                return root->right;
            }
            root = nullptr;
        }

        return root;
    }
};
