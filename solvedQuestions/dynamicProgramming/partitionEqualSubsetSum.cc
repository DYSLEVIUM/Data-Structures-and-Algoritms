// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum = accumulate(arr, arr+N, 0);
        
        if(sum&1) return 0;
        
        int target = sum>>1;
        vector<vector<bool>> dp(N+1, vector<bool>(target+1));
        
        for(int i=0;i<N+1;++i){
            for(int j=0;j<target+1;++j){
                if(i==0||j==0){
                    if(i==0) dp[i][j] = 0;
                    if(j==0) dp[i][j] = 1;
                }else{
                    if(j-arr[i-1]>=0){
                        dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
                    }else{
                        dp[i][j] = dp[i-1][j];
                    }
                }
            }
        }
        
        return dp[N][target];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends
