// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int maximumPath(int N, vector<vector<int>> Matrix)
    {
        // code here
        vector<vector<int>> dp(N, vector<int>(N));
        
        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                dp[i][j] = Matrix[i][j];
                
                int maxi = 0;
                if(i-1>=0){
                    maxi = dp[i-1][j];
                    if(j-1>=0) maxi = max(maxi, dp[i-1][j-1]);
                    if(j+1<N) maxi = max(maxi, dp[i-1][j+1]);
                }
                
                dp[i][j]+=maxi;
            }
        }
        
        int ans = INT_MIN;
        
        for(int i=0;i<N;++i) ans = max(ans, dp[N-1][i]);
        
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  // } Driver Code Ends
