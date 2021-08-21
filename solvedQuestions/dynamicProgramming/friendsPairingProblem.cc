// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    int countFriendsPairings(int n) 
    { 
        // code here
        long long MOD = 1e9+7;
        long long prevPrev = 1;
        long long prev = 2;
        
        if(n==1) return prevPrev;
        if(n==2) return prev;
        
        long long ans;
        
        for(long long i=3;i<n+1;++i){
            ans=(prev%MOD)+((i-1)*(prevPrev%MOD))%MOD;
            ans%=MOD;
            prevPrev = prev;
            prev = ans;
        }
        
        return ans;
    }
};    
 

// { Driver Code Starts.
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends
