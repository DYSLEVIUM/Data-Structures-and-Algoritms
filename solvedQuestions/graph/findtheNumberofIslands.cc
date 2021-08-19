// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the number of islands.
    int numIslands(vector<vector<char>>& grid) 
    {
        // Code here
        // vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
    
        auto dfs = [&grid](const int& i, const int& j, const auto& dfs){
            if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]=='0') return;
            
            // visited[i][j] = true;
            grid[i][j] = '0';   //  added this for space optimization
            
            static int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
            static int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
            
            for(int k=0;k<8;++k) dfs(i+row[k], j+col[k], dfs);
        };
    
        int comp = 0;
        for(int i=0;i<grid.size();++i){
            for(int j=0;j<grid[0].size();++j){
                if(grid[i][j]=='1') {   //  check visited if space can be used
                    ++comp;
                    dfs(i,j, dfs);
                }
            }
        }
        
        return comp;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends
