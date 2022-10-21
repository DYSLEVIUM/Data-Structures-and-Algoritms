class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_set<string> dict(dictionary.begin(), dictionary.end());

        stringstream ss(sentence);
        string ans, word;
        while(ss >> word) {
            string pref;
            for(auto & ch : word) {
                pref += ch;
                if(dict.count(pref)) break;
            }
            ans += pref;
            ans += ' ';
        }
        ans.pop_back();
        return ans;
    }
};
