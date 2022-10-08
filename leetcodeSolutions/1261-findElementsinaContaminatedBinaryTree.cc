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
class FindElements {
public:
    FindElements(TreeNode* root) {
        root->val = 0;
        auto dfs = [&](const auto &dfs, TreeNode * const node){
            if(!node) {
                return ;
            }

            m_se.insert(node->val);

            if(node->left) {
                node->left->val = 2 * node->val + 1;
            }

            if(node->right) {
                node->right->val = 2 * node->val + 2;
            }

            dfs(dfs, node->left), dfs(dfs, node->right);
        };
        dfs(dfs, root);
    }
    
    bool find(int target) {
        return m_se.count(target);
    }

private:
    unordered_set<int> m_se;
};

/**
 * Your FindElements object will be instantiated and called as such:
 * FindElements* obj = new FindElements(root);
 * bool param_1 = obj->find(target);
 */
