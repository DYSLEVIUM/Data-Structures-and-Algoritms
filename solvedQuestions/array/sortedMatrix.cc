// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<vector<int>> sortedMatrix(int n, vector<vector<int>> mat) {
        // code here
        vector<int> ele(n*n);
        
        int idx=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                ele[idx++] = mat[i][j];
            }
        }
        
        sort(ele.begin(),ele.end());
        
        idx=0;
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                mat[i][j] = ele[idx++];
            }
        }
        
        return mat;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
}  // } Driver Code Ends
