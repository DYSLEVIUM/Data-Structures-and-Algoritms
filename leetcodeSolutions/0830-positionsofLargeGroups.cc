class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        int n = s.size();

        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i) {
            int j = i;
            while(j < n && s[i] == s[j]) {
                ++j;
            }

            if(j - i >= 3) {
                ans.push_back({i, j - 1});
            }
            
            i = j - 1;
        }

        return ans;
    }
};
