class Solution {
public:
    vector<int> goodDaysToRobBank(vector<int>& security, int time) {
        cin.tie(nullptr)->sync_with_stdio(false);
        
        int n = security.size();

        int cnt = 1;
        
        vector<int> pre(n);
        pre[0] = 1;
        for(int i = 1; i < n; ++i) {
            cnt = security[i] <= security[i - 1] ? cnt + 1 : 1;
            pre[i] = cnt;
        }

        cnt = 1;
        vector<int> suff(n);
        suff[n - 1] = 1;
        for(int i = n - 2; i >=0; --i) {
            cnt = security[i] <= security[i + 1] ? cnt + 1 : 1;
            suff[i] = cnt;
        }

        vector<int> ans;
        ans.reserve(n);
        for(int i = 0; i < n; ++i) {
            // if the running validity is more than time for both forwards and backwards
            if(pre[i] - 1 >= time && suff[i] - 1 >= time) { // subtracting 1 as we are counting the current element also
                ans.push_back(i);
            }
        }

        return ans;
    }
};
