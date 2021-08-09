// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> ans;
    
    void findPath(vector<vector<int>> &m, int n, vector<vector<bool>>& visited, int row=0, int col=0, string currAns=""){
        if(row>=n || col>=n || row<0 || col<0 || m[row][col]==0 || visited[row][col]==true) return;
        
        if(row==n-1 && col==n-1) {
            ans.push_back(currAns);
            return;
        }
        
        int x[] = {1,0,-1,0};
        int y[] = {0,1,0,-1};
        
        visited[row][col] = true;
        
        for(int i=0;i<4;++i){
            string tempS = currAns;
            
            if(i==0) tempS+='D';
            else if(i==1) tempS+='R';
            else if(i==2) tempS+='U';
            else tempS+='L';                
            
            findPath(m, n, visited, row+x[i], col+y[i], tempS);
        }
        
        visited[row][col] = false;
    }
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        // Your code goes here
        vector<vector<bool>> visited(n+1, vector<bool>(n+1, false));
        
        findPath(m, n, visited);
        
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};

    


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}  // } Driver Code Ends
