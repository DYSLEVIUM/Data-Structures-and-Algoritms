//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) {
        int l_ptr = 0, r_ptr = n - 1;
        
        while(l_ptr < r_ptr) {
            // if l knows r, l can't be celebrity else if l doesn't know r, r can't be celebrity
            if(M[l_ptr][r_ptr]) {
                ++l_ptr;
            } else {
                --r_ptr;
            }
        }
        
        for(int i = 0; i < n; ++i) {
            // the candidate celebrity should not know anyone and others should know him
            if(M[l_ptr][i] || (i != l_ptr && !M[i][l_ptr])) {
                return -1;
            }
        }
        
        return l_ptr;
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends
