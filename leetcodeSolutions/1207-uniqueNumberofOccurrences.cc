class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int, int> mp;
        for(auto &num : arr) {
            ++mp[num];
        }

        unordered_set<int> se;
        for(auto &[_, cnt] : mp) {
            if(se.count(cnt)) {
                return false;
            }
            se.insert(cnt);
        }

        return true;
    }
};
