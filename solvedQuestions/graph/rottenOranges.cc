// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(const vector<vector<int>>& grid) {
        // Code here
        int rows = grid.size(), cols = grid[0].size();
        
        vector<vector<bool>> visited(rows, vector<bool>(cols));
        
        auto is_valid_cell = [&](const int &row, const int &col){
            if(row < 0 || row >= rows || col < 0 || col >= cols || visited[row][col]) {
                return false;
            }
            
            return true;
        };
        
        queue<pair<int, int>> qu;
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(grid[row][col] == 2) {
                    qu.push({row, col});            
                    visited[row][col] = true;
                } else if(!grid[row][col]) {
                    visited[row][col] = true;
                }
            }
        }
        
        vector<pair<int, int>> delta{{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        int ttime = 0;
        while(!qu.empty()) {
            int curr_size = qu.size();
            while(curr_size--) {
                int row = qu.front().first, col = qu.front().second;
                qu.pop();
                
                for(int i = 0; i < delta.size(); ++i) {
                    int dx = delta[i].first, dy = delta[i].second;
                    int new_row = row + dx, new_col = col + dy;
                    if(is_valid_cell(new_row, new_col)) {
                        visited[new_row][new_col] = true;
                        qu.push({new_row, new_col});
                    }
                }
            }
            
            ++ttime;
        }
        --ttime;    //  not counting the last unit time when the queue is empty
        
        for(int row = 0; row < rows; ++row) {
            for(int col = 0; col < cols; ++col) {
                if(!visited[row][col]) {
                    return -1;
                }
            }
        }
        
        return ttime;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends
