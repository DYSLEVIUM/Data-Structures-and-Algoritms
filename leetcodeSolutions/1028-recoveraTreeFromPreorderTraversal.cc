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
    TreeNode* recoverFromPreorder(string traversal) {
        int n = traversal.size();
        auto dfs = [&](const auto &dfs, int &idx, const int &d) -> TreeNode * {
            if(idx == n) {
                return nullptr;
            }

            int num = 0;
            while(idx < n && traversal[idx] >= '0' && traversal[idx] <= '9') {
                num = num * 10 + traversal[idx++] - '0';
            }
            TreeNode * node = new TreeNode(num);

            int cnt = 0;
            while(idx + cnt < n && traversal[idx + cnt] == '-') {
                ++cnt;
            }
            // cout << "L: " << cnt << ' ' << d + 1 << '\n';
            if(cnt == d + 1) {
                idx += cnt;
                node->left = dfs(dfs, idx , d + 1);
            }

            cnt = 0;
            while(idx + cnt < n && traversal[idx + cnt] == '-') {
                ++cnt;
            }
            // cout << "R: " << cnt << ' ' << d + 1 << '\n';
            if(cnt == d + 1) {
                idx += cnt;
                node->right = dfs(dfs, idx, d + 1);
            }

            return node;
        };
  
        int idx = 0;
        return dfs(dfs, idx, 0);
    }
};
