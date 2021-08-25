// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges. 
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        queue<vector<int>> qu;    //  store time and node
        
        //  getting initial rotten tomatoes
        for(int x=0;x<grid.size();++x){
            for(int y=0;y<grid[x].size();++y){
                if(grid[x][y] == 2) qu.push(vector<int>({x, y}));
            }
        }
        
        vector<vector<int>> ds = {{0, -1}, {1, 0}, {0, 1}, {-1, 0}};    //  dx, dy
    
        auto checkIndex = [&grid](const int& x, const int& y){
            if(x < 0 || x >= grid.size() || y < 0 || y >= grid[0].size()) return false; //  out of bounds check
            
            if(grid[x][y]==2 || grid[x][y]==0) return false;    //  check if it already rotten
            
            return true;
        };
        
        int t = 0;
        
        //  multisource bfs
        while(!qu.empty()){
            int sz = qu.size();
            
            while(sz--){
                vector<int> fr = qu.front();
                qu.pop();
                
                for(int i=0;i<ds.size();++i){
                    if(checkIndex(fr[0]+ds[i][0], fr[1]+ds[i][1])) {
                        grid[fr[0]+ds[i][0]][fr[1]+ds[i][1]] = 2;   //  rotting that tomato
                        
                        qu.push(vector<int>({fr[0]+ds[i][0], fr[1]+ds[i][1]}));
                    }
                }
            }
            
            if(!qu.empty()) ++t;    //  if queue is not empty, it will take at least one unit of time
        }
        
        //  checking if any fresh tomatoes are left
        for(int x=0;x<grid.size();++x){
            for(int y=0;y<grid[x].size();++y){
                if(grid[x][y] == 1) return -1;
            }
        }
        
        return t;
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
