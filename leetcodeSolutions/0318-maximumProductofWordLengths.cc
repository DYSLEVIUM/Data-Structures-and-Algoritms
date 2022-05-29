class Solution {
public:
    int maxProduct(vector<string>& words) {
        int n = words.size();
        
        vector<int> masks(n);
        int ans = 0;
        
        for(int i = 0; i < n; ++i) {
            int mask = 0;
            for(char &ch: words[i]) {
                mask |= 1 << (ch - 'a');
            }
            masks[i] = mask;
        }
        
        for(int i = 0; i < n; ++i) {
            for(int j = i + 1; j < n; ++j) {
                if(!(masks[i] & masks[j])) {
                    ans = max(ans, int(words[i].length()) * int(words[j].length()));
                }
            }
        }
        
        return ans;
    }
};
