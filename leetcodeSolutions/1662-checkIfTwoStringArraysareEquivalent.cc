class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int i = 0, ii = 0, j = 0, jj = 0;
        while(i < word1.size() && j < word2.size()) {
            if(word1[i][ii] != word2[j][jj]) {
                return false;
            }

            ++ii, ++jj;

            if(ii == word1[i].size()) {
                ++i, ii = 0;
            }

            if(jj == word2[j].size()) {
                ++j, jj = 0;
            }
        }

        // final check of reaching the end
        bool is_valid = i == word1.size() && j == word2.size();
        is_valid &= !ii && !jj;

        return is_valid;
    }
};
