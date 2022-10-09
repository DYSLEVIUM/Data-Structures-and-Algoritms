class Solution {
public:
    string toGoatLatin(string sentence) {
        unordered_set<char> vowels{'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};

        vector<string> words;
        stringstream ss(sentence);
        string word;
        while(ss >> word) {
            words.push_back(word);
        }

        string ans;
        for(int i = 0; i < words.size(); ++i) {
            if(!vowels.count(words[i][0])) {
                for(int j = 1; j < words[i].size(); ++j) {
                    ans += words[i][j];
                }
                ans += words[i][0];
            } else {
                ans += words[i];
            }
            
            ans += "ma";
            for(int j = 0; j < i + 1; ++j) {
                ans += 'a';
            }

            ans += ' ';
        }
        ans.pop_back();

        return ans;
    }
};
