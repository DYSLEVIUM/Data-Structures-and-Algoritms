class Solution {
public:
    int largestValsFromLabels(vector<int>& values, vector<int>& labels, int numWanted, int useLimit) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = values.size();

        vector<pair<int, int>> vals_labs(n);
        for(int i = 0; i < n; ++i) {
            vals_labs[i] = { values[i], labels[i] };
        }
        sort(vals_labs.rbegin(), vals_labs.rend());
    
        int ans = 0, i = 0;
        unordered_map<int, int> used;
        while(numWanted--) {
            while(i < n && used[vals_labs[i].second] == useLimit) {
                ++i;
            }

            if(i == n) {
                break;
            }

            const auto & [val, lab] = vals_labs[i++];
            ans += val;
            ++used[lab];
        }

        return ans;
    }
};
