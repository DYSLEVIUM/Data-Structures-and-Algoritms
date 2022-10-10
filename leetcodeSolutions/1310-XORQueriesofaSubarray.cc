class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        int n = arr.size(), m = queries.size();
        
        vector<int> pre = arr;
        for(int i = 1; i < n; ++i) {
            pre[i] ^= pre[i - 1];
        }

        vector<int> ans(m);
        for(int i = 0; i < m; ++i) {
            int le = queries[i][0], ri = queries[i][1];
            ans[i] = pre[ri] ^ (le - 1 < 0 ? 0 : pre[le - 1]);
        }

        return ans;
    }
};
