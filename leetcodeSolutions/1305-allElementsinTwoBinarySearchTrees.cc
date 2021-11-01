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
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        
        multiset<int> se;
        
        auto travelTree = [&se](TreeNode* root, const auto& travelTree){
            if(root==nullptr) return;  
            
            se.insert(root->val);
            
            travelTree(root->left, travelTree);
            travelTree(root->right, travelTree);
        };
        
        travelTree(root1, travelTree);
        travelTree(root2, travelTree);

        return vector<int>(se.begin(), se.end());
    }
};
