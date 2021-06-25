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
        typedef long long ll;
        
        const ll MOD = 1e9+7;
        
        if(n==1) return k;
        
        ll diff = k*(k-1);
        ll same = k;
        
        for(ll i=3;i<n+1;++i){
            ll prev = diff;
            diff = ((diff+same)*(k-1))%MOD;
            same = prev;
        }
        
        return (diff+same)%MOD;
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
