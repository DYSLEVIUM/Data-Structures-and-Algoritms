class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words[0].size();
        
        unordered_set<string> se;
        for(auto &word: words) {
            string odd, even;
            for(int i = 0; i < n; ++i) {
                if(i & 1) {
                    odd += word[i];
                }
                else {
                    even += word[i];
                }
            }
            sort(odd.begin(), odd.end()), sort(even.begin(), even.end());
            se.insert(odd + even);
        }

        return se.size();
    }
};
