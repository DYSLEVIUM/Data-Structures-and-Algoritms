class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int cnt = 0;
        for(auto &word : words) {
            int i = 0, j = 0, curr = 0;
            while(i < word.size() && j < s.size()) {
                if(word[i] == s[j]) {
                    ++i, ++j;
                } else {
                    break;
                }
            }
            cnt += i == word.size();
        }

        return cnt;
    }
};
