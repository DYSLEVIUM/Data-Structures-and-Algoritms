// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>> ds = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
	    
	    auto checkValidCell = [&N](const int& x, const int& y){
	        if(x < 1 || x > N || y < 1 || y > N) return false;
	        return true;
	    };
	    
	    //  we need this visited grid so that we don't end up in a loop (giviing runtime error if not used, probably memory is beig exceeded when the grid is too large and the target is far)
	    vector<vector<bool>> visited(N+1, vector<bool>(N+1, false));
	    
	    int step = 0;
	    queue<vector<int>> qu;
	    qu.push(vector<int>({KnightPos[0], KnightPos[1]}));

	    //  multi-source BFS
	    while(!qu.empty()){
	        int size = qu.size();
	        
	        while(size--){
	            vector<int> fr = qu.front();
	            qu.pop();
	            
	            if(fr[0]==TargetPos[0] && fr[1]==TargetPos[1]) return step;
	            
	            for(int i=0;i<ds.size();++i){
	                if(checkValidCell(fr[0]+ds[i][0], fr[1]+ds[i][1]) && !visited[fr[0]+ds[i][0]][fr[1]+ds[i][1]]){
	                    visited[fr[0]+ds[i][0]][fr[1]+ds[i][1]]=true;
	                    qu.push(vector<int>({fr[0]+ds[i][0], fr[1]+ds[i][1]}));
	                } 
	            }
	        }
	        
	        ++step;
	    }
	    
	    return step;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends
