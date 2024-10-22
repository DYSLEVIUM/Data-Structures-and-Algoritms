#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;

        queue<TreeNode*> qu;
        qu.push(root);

        while(!qu.empty()) {
            int sz = qu.size();
            long long sum = 0;
            while(sz--){
                auto fr = qu.front();
                qu.pop();

                sum += 1LL * fr->val;
                
                if(fr->left) {
                    qu.push(fr->left);
                }

                if(fr->right) {
                    qu.push(fr->right);
                }
            }

            pq.push(sum);
            if(pq.size() > k) {
                pq.pop();
            }
        }

        if(pq.size() < k) {
            return -1;
        }

        return pq.top();
    }
};
