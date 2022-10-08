class Solution {
public:
    char repeatedCharacter(string s) {
        unordered_set<char> se;
        for(auto &ch : s) {
            if(se.count(ch)) {
                return ch;
            }
            se.insert(ch);
        }

        return '#';
    }
};
