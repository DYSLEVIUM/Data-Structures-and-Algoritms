class Solution {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
        int n = grid.size();
        
        int ans = 0;
        
        vector<int> maxRow(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                maxRow[i] = max(maxRow[i], grid[i][j]);   
            }
        }
        
        vector<int> maxCol(n);
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                maxCol[i] = max(maxCol[i], grid[j][i]);
            }
        }
        
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                ans+=abs(grid[i][j]-min(maxRow[i], maxCol[j]));
            }
        }
        
        return ans;
    }
};
