class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();

        queue<pair<int,int>> multiSourceBFS;
        
        int cnt = 0;

        for(int i=0;i<row;++i){
            for(int j=0;j<col;++j){
                if(grid[i][j]==2) multiSourceBFS.push({i,j});
                cnt+= grid[i][j]==1;
            }
        }
        
        int ans = 0;
        
        while(cnt){
            int sz = multiSourceBFS.size();
            
            int prevCnt = cnt;
            
            while(sz--){
                auto [i, j] = multiSourceBFS.front();
                multiSourceBFS.pop();
                
                if(i-1>=0 && grid[i-1][j]==1) multiSourceBFS.push({i-1,j}), --cnt, grid[i-1][j] = 2;
                if(i+1<row && grid[i+1][j]==1) multiSourceBFS.push({i+1,j}), --cnt, grid[i+1][j] = 2;
                if(j-1>=0 && grid[i][j-1]==1) multiSourceBFS.push({i,j-1}), --cnt, grid[i][j-1] = 2;
                if(j+1<col && grid[i][j+1]==1) multiSourceBFS.push({i,j+1}), --cnt, grid[i][j+1] = 2;
            }
            
            // oranges grid has more than one component
            if(prevCnt == cnt) break;   

            ++ans;
        }
        
        return cnt==0?ans:-1;
    }
};
