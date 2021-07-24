// { Driver Code Starts
#include <bits/stdc++.h>
#include<stdio.h>
#include<math.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    long long countWays(int n, int k){
        // code here
        long long MOD = 1e9+7;
        
        if(n==1) return k;
        
        int l2Same = k;
        int l2Diff = k* (k - 1);
        
        for(int i = 2; i < n; ++i){
            int te = l2Diff;
            
            l2Diff = (((l2Same + l2Diff) % MOD) * (k - 1)) % MOD;
            l2Same = te;
        }
        
        return (l2Same + l2Diff) % MOD;
    }
};

// { Driver Code Starts.

int main()
{
	
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		Solution ob;
		cout<<ob.countWays(n,k)<<endl;
	}
	return 0;
}  // } Driver Code Ends
