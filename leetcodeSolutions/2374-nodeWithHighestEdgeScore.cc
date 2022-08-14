class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int n = edges.size();
        
        vector<long long> ans(n);
        for(int i = 0; i < n; ++i) {
            ans[edges[i]] += i;
        }
        
        long long maxx = INT_MIN, maxx_idx = -1;
        for(int i = 0; i < n; ++i) {
            if(maxx < ans[i]) {
                maxx = ans[i];
                maxx_idx = i;
            }
        }
        
        return maxx_idx;
    }
};
