class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int maxx = 0;
        unordered_map<int, int> mp;
        for(const int & num : nums) {
            maxx = max(maxx, ++mp[num]);
        }

        vector<vector<int>> ans;
        ans.reserve(maxx);
        while(!mp.empty()) {
            vector<int> curr;
            unordered_set<int> eras;
            for(auto & [k, v]: mp) {
                curr.push_back(k);
                --v;

                if(!v) {
                    eras.insert(k);
                }
            }

            for(const auto & num : eras) {
                mp.erase(num);
            }

            ans.push_back(curr);
        }

        return ans;
    }
};
