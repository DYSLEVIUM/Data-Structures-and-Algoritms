#pragma GCC optimize("O3", "unroll-loops")

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

static const int _ = [](){
    cin.tie(nullptr)->sync_with_stdio(false);
    return 0;
}();

class Solution {
public:
    bool isEvenOddTree(TreeNode * const root) {
        if(!root) {
            return false;
        }

        constinit static int INF = 0x3f3f3f;

        queue<TreeNode *> qu;
        qu.push(root);

        bool lvl_parity = 0;

        while(!qu.empty()) {
            int sz = qu.size(), prev = lvl_parity ? INF : -INF;
            while(sz--) {
                const TreeNode * node = qu.front();
                qu.pop();

                int parity = node->val & 1;
                if(lvl_parity) {
                    if(node->val >= prev || parity) {
                        return false;
                    }
                } else {
                    if(node->val <= prev || !parity) {
                        return false;
                    }
                }

                if(node->left) {
                    qu.push(node->left);
                }

                if(node->right) {
                    qu.push(node->right);
                }

                prev = node->val;
            }

            lvl_parity ^= 0 ^ 1;
        }

        return true;
    }
};
