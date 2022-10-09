class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<char> punc{'!', '?', '\'', ',', ';', '.'};

        for(auto &ch : paragraph) {
            if(punc.count(ch)) {
                ch = ' ';
            }
        }

        unordered_set<string> se(banned.begin(), banned.end());
        unordered_map<string, int> mp;

        stringstream ss(paragraph);
        string word;
        while(ss >> word) {
            transform(word.begin(), word.end(), word.begin(), ::tolower);

            if(se.count(word)) {
                continue;
            }

            ++mp[word];
        }

        string ans;
        int freq = 0;
        for(auto &[word, cnt] : mp) {
            if(cnt > freq) {
                freq = cnt;
                ans = word;
            }
        }

        return ans;
    }
};
