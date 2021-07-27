// { Driver Code Starts

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution {
  public:
    int countSquares(int n) {
        // code here
        long te = sqrt(n);
        
        if(te*te==n) return sqrt(n)-1;
        
        return sqrt(n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
