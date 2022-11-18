class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int rows = strs.size(), cols = strs[0].size();
        int ans = 0;
        for(int col = 0; col < cols; ++col) {
            char prev = 'a' - 1;
            bool ok = true;
            for(int row = 0; row < rows; ++row) {
                if(strs[row][col] < prev) {
                    ok = false;
                    break;
                }
                prev = strs[row][col];
            }

            ans += ok;
        }

        return cols - ans;
    }
};
