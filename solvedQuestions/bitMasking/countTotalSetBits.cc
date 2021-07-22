// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        if (!n) return 0;
        
        int mx = floor(log2(n));
        
        //  if x = 13
        //  1. 50% of bits till log2(13) will be 1
        //  2. 13 - 8 + 1 (8 is included in this calc)
        //  3. now we solve for the smaller problem 
        
        return ((1 << (mx - 1)) * mx) + (n - (1 << mx) + 1) + countSetBits(n - (1 << mx));
    }
};


// { Driver Code Starts.

// Driver code
int main()
{
	 int t;
	 cin>>t;// input testcases
	 while(t--) //while testcases exist
	 {
	       int n;
	       cin>>n; //input n
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;// print the answer
	  }
	  return 0;
}
  // } Driver Code Ends
