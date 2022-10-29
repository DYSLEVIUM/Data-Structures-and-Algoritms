class Solution1 {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();

        // can be optimized using trie
        vector<string> ans;
        for(string & query : queries) {
            for(string & word : dictionary) {
                int diff = 0;
                for(int i = 0; i < n; ++i) diff += query[i] != word[i];
                if(diff < 3) {
                    ans.push_back(query);
                    break;
                }
            }
        }
        
        return ans;
    }
};
