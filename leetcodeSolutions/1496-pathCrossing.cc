class Solution {
public:
    bool isPathCrossing(const string & path) {
        cin.tie(nullptr)->sync_with_stdio(false);

        unordered_map<char, pair<int, int>> mp;
        mp['N'] = {0, -1};
        mp['S'] = {0, 1};
        mp['E'] = {-1, 0};
        mp['W'] = {1, 0};

        pair<int, int> loc = {0, 0};

        unordered_set<string> se;
        se.insert("0+0");
        for(const char & c : path) {
            auto delta = mp[c];
            loc.first += delta.first, loc.second += delta.second;

            string s = to_string(loc.first) + "+" + to_string(loc.second);
            if(se.count(s)) {
                return true;
            }
            se.insert(s);
        }

        return false;
    }
};
