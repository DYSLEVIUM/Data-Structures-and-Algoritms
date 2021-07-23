// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
//	Time: O(nm) 
//	Space: O(nm) 
//         vector<vector<long long>> dp(n + 1, vector<long long>(m + 1, 0));
    
//         for(int i = 0; i < n + 1; ++i){
//             for(int j = 0; j < m + 1; ++j){
//                 if(i == 0 || j == 0){
//                     if(j == 0) dp[i][j] = 0;
//                     if(i == 0) dp[i][j] = 1;
//                 }else{
//                     dp[i][j] += dp[i][j-1];
                    
//                     if(i - S[j-1] >= 0) dp[i][j] += dp[i - S[j - 1]][j];
//                 }
//             }
//         }
        
//         return dp[n][m];
	
//	Time: O(nm) 
//	Space: O(n) 
	    
	vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        
	//	here, we first iterate over the available coins for a current value (if we do it the other way, we also end up addng the permutation, which is incorrect)
        for(int i = 0; i < m; ++i){
            for(int j = 0; j < n + 1; ++j){
                if(j - S[i] >= 0){
                    dp[j] += dp[j - S[i]];
                }
            }
        }
        
        return dp[n];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  // } Driver Code Ends
