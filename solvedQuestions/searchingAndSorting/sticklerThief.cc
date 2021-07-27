// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        //  O(n) space
        //  O(n) time
        
        // vector<vector<int>> dp(n, vector<int>(2));
        // dp[0][0] = 0;
        // dp[0][1] = arr[0];
        
        // int ans = dp[0][1];
        
        // for(int i = 1; i < n; ++i){
        //     dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
        //     dp[i][1] = dp[i-1][0] + arr[i];
            
        //     ans = max({ans, dp[i][0], dp[i][1]});
        // }
        
        
        // return ans;
        
        //  O(1) space
        //  O(n) time
        
        int notTakenCurr = 0, takenCurr = arr[0];
        
        int ans = takenCurr;
        
        for(int i=1;i<n;++i){
            int temp = notTakenCurr;
            
            notTakenCurr = max(takenCurr, notTakenCurr);
            takenCurr = temp + arr[i];
            
            ans = max({ans, takenCurr, notTakenCurr});
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends
