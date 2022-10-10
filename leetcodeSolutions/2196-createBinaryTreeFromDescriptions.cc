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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, TreeNode *> mp;
        unordered_set<TreeNode *> not_root;
        for(auto &description : descriptions) {
            int parent = description[0], child = description[1], child_type = description[2];
            if(!mp.count(parent)) {
                mp[parent] = new TreeNode(parent);
            }

            if(!mp.count(child)) {
                mp[child] = new TreeNode(child);
            }

            if(child_type) {
                mp[parent]->left = mp[child];
            } else {
                mp[parent]->right = mp[child];
            }

            not_root.insert(mp[child]);
        }

        TreeNode *root;
        for(auto &[_, node] : mp) {
            if(!not_root.count(node)) {
                root = node;
                break;
            }
        }

        return root;
    }
};
