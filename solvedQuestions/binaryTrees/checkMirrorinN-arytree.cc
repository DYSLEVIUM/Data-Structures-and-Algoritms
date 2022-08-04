//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
    int checkMirrorTree(int n, int e, int A[], int B[]) {
        vector<vector<int>> edges1(n);
        vector<vector<int>> edges2(n);
        
        for(int i = 0; i < 2 * e; i += 2) {
            edges1[A[i] - 1].push_back(A[i + 1] - 1);
            edges2[B[i] - 1].push_back(B[i + 1] - 1);
        }
        
        for(int i = 0; i < n; ++i) {
            reverse(edges2[i].begin(), edges2[i].end());
        }
        
        for(int i = 0; i < n; ++i) {
            if(edges1[i] != edges2[i]) {
                return false;
            }
        }
        
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n,e;
        
        cin>>n>>e;
        int A[2*e], B[2*e];
        
        for(int i=0; i<2*e; i++)
            cin>>A[i];
            
        for(int i=0; i<2*e; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.checkMirrorTree(n,e,A,B) << endl;
    }
    return 0;
}
// } Driver Code Ends
