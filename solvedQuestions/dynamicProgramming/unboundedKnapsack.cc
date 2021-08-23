// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // code here
        vector<vector<int>> dp(N+1, vector<int>(W+1));
        
        for(int i=0;i<N+1;++i){
            for(int j=0;j<W+1;++j){
                if(i==0 || j==0){
                    dp[i][j]= 0;
                }else{
                    if(j-wt[i-1]>=0){
                        dp[i][j] = max(dp[i-1][j], dp[i][j-wt[i-1]]+val[i-1]);
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[N][W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends
