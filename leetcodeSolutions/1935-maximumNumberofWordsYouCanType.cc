class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> se(brokenLetters.begin(), brokenLetters.end());

        int cnt = 0;
        
        stringstream ss(text);
        string word;
        while(ss >> word) {
            bool ok = true;
            for(auto &ch : word) {
                if(se.count(ch)) {
                    ok = false;
                    break;
                }
            }
            cnt += ok;
        }

        return cnt;
    }
};
