#pragma GCC optimize("O3", "unroll-loops")

auto _ = [](){
    return cin.tie(nullptr)->sync_with_stdio(false);
}();

class Solution {
public:
    vector<string> removeSubfolders(vector<string> & folder) {
        const int n = folder.size();

        sort(folder.begin(), folder.end());

        vector<string> ans;
        ans.push_back(move(folder[0]));

        for(int i = 1; i < n; ++i) {
            if(folder[i].starts_with(ans.back() + '/')) {
                continue;
            }

            ans.push_back(move(folder[i]));
        }

        return ans;
    }
};
