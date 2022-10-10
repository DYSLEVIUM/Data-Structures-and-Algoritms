class Solution {
public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        constexpr int CHAR_SET = 26;
        static_assert(CHAR_SET == 26);

        int fact[] = {1, 1, 2, 6, 24, 120, 720, 5040};
        auto perm = [&fact](const string &s){
            int fa[CHAR_SET] = {};
            for(auto &ch : s) {
                ++fa[ch - 'A'];
            }
            
            int res = fact[s.size()];

            // removing over-counting
            for(auto &num : fa) {
                res /= fact[num];
            }

            return res;
        };

        unordered_set<string> se;
        auto dfs = [&](const auto &dfs, const int &idx, const string &curr){
            if(idx == n) {
                // if we have not found the string yet
                return se.insert(curr).second ? perm(curr) : 0;
            }

            // take the curr index and not take the curr index
            return dfs(dfs, idx + 1, curr) + dfs(dfs, idx + 1, curr + tiles[idx]);
        };
        // we need to sort it because, CD and DC will form the same, but in the set they will be different, so we sort them
        sort(tiles.begin(), tiles.end());
        return dfs(dfs, 0, "") - 1; // -1 for empty string
    }
};
