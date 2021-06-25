// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;



 // } Driver Code Ends

class Solution
{
    public:
    //Function to find the maximum number of cuts.
    int maximizeTheCuts(int n, int x, int y, int z)
    {
        //Your code here
        vector<long long> dp(n+1);
        dp[0] = 0;
        
        for(long long i=1;i<n+1;++i){
            long long t = -__LONG_LONG_MAX__;
            if(i-x>=0 && dp[i-x]!= -__LONG_LONG_MAX__){
                t = max(t,1+dp[i-x]);
            }
            if(i-y>=0 && dp[i-y]!= -__LONG_LONG_MAX__){
                t = max(t,1+dp[i-y]);
            }
            if(i-z>=0 && dp[i-z]!= -__LONG_LONG_MAX__){
                t = max(t,1+dp[i-z]);
            }
            
            dp[i] = t;
        }
        
        if(dp[n] == -__LONG_LONG_MAX__) return 0;
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main() {
    
    //taking testcases
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;
        
        //taking types of segments
        int x,y,z;
        cin>>x>>y>>z;
        Solution obj;
        //calling function maximizeTheCuts()
        cout<<obj.maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}  // } Driver Code Ends
