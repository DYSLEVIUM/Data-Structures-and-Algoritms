class Solution {
public:
    string arrangeWords(const string & text) {
        vector<pair<string, int>> words;
        
        int i = 0;
        string word;
        stringstream ss(text);
        while(ss >> word) {
            for(auto & ch : word) ch |= ' '; // making lowercase
            words.push_back({word, i++});
        }

        sort(words.begin(), words.end(), [](const pair<string, int> & lhs, const pair<string, int> & rhs){
            if(lhs.first.size() == rhs.first.size()) return lhs.second < rhs.second;
            return lhs.first.size() < rhs.first.size();
        });

        string ans;
        for(auto & [s, _] : words) ans += s, ans += ' ';
        ans.pop_back(); // remove last space
        ans[0] &= '_'; // making uppercase

        return ans;
    }
};
