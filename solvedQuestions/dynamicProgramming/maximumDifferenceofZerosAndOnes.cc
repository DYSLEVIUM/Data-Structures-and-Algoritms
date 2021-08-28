// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int maxSubstring(string S)
	{
	    // Your code goes here
	    int sum = 0;
	    int best = INT_MIN;
	    
	    for(auto x:S){
	        if(x=='1') sum = max(sum-1, -1);
	        else sum = max(sum+1, 1);
	        
	        best = max(best, sum);
	    }
	    
	    if(best==INT_MIN) return -1;
	    
	    return best;
	}
};

// { Driver Code Starts.

int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}
  // } Driver Code Ends
