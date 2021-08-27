// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++

class Solution {
  public:
    int getMinDiff(int arr[], int n, int k) {
        // code here
        sort(arr, arr+n);
        
        //  current ans
        int ans = arr[n-1]-arr[0];
        
        int smallest = arr[0]+k;
        int largest = arr[n-1]-k;
        
        int mini;
        int maxi;
        
        //  we will try to find the critical point where, in one element after adding k and in other element subtracting k, we get the greatest minimum and the smallest maximum
        //  we achive this by greedily increasing the smaller one and decrease the larger one
        //  basically, we are rotating the array about the critical point by adding and subtracting k, so that we get a smaller range
        for(int i=0;i<n-1;++i){
            maxi = max(largest, arr[i]+k);
            mini = min(smallest, arr[i+1]-k);
            
            //  negative height towers is not possible
            if(mini<0) continue;
            
            ans = min(ans, maxi-mini);
        }
        
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> k;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getMinDiff(arr, n, k);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends
