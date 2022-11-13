class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        vector<string> words;
        for(string word; ss >> word;) words.push_back(word);
        
        string ans;
        for(int i = words.size() - 1; i >= 0; --i) ans += words[i] + " ";
        ans.pop_back();

        return ans;
    }
};
