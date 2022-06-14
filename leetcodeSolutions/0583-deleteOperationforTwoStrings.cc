class Solution {
public:
    int minDistance(string word1, string word2) {
        //  longest common subsequence
        int n1 = word1.size(), n2 = word2.size();
        
        if(n1 < n2) {
            swap(word1, word2);
            swap(n1, n2);
        }
        
        vector<int> curr(n2 + 1), prev(n2 + 1);
        for(int i = 1; i < n1 + 1; ++i) {
            for(int j = 1; j < n2 + 1; ++j) {                                
                if(word1[i - 1] == word2[j - 1]) {
                    curr[j] = 1 + prev[j - 1];
                } else {
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }
            prev = curr;
        }
        
        return n1 + n2 - 2 * curr[n2];
    }
};
