class Solution {
public:
    int minDistance(string word1, string word2) {
        int n1 = word1.size(), n2 = word2.size();
        
        vector<vector<int>> best_matches(n1 + 1, vector<int>(n2 + 1));
        for(int i = 0; i < n1 + 1; ++i) {
            for(int j = 0; j < n2 + 1; ++j) {
                if(!i || !j) {
                    if(!i) best_matches[i][j] = j;
                    if(!j) best_matches[i][j] = i;
                    
                    if(!i && !j) best_matches[i][j] = 0;
                    continue;
                }
                
                if(word1[i - 1] == word2[j - 1]) {
                    best_matches[i][j] = best_matches[i - 1][j - 1];
                } else {
                    best_matches[i][j] = 1 + min({best_matches[i][j - 1], best_matches[i - 1][j], best_matches[i - 1][j - 1]});
                }
            }
        }
        
        return best_matches[n1][n2];
    }
};
