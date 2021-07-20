// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    int findPosition(int N) {
        // code here
        
        if (N==0) return -1;
        
        int ans = 0;
        
        int iter = 1;
        
        int tempN = N;
        while(N){
            if(N&1){
                if(ans!=0) ans = -1;
                else ans = iter;
            }
            N>>=1;
            ++iter;
        }
        
        return ans;
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
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  // } Driver Code Ends
