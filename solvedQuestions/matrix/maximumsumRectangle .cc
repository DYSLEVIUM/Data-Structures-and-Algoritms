// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int maximumSumRectangle(int R, int C, vector<vector<int>> M) {
        // code here
        auto kadane = [&](const vector<int> pref_col){
            //  taking at least 1 cell
            int curr = pref_col[0], maxx = pref_col[0];
            for(int col = 1; col < C; ++col) {
                curr = max(curr + pref_col[col], pref_col[col]);
                maxx = max(maxx, curr);
            }
            
            return maxx;
        };
        
        //  we suppose the matrix is starting from the rowth row
        int maxx = INT_MIN;
        for(int row = 0; row < R; ++row) {
            vector<int> pref_col(C, 0);
            for(int row_start = row; row_start < R; ++row_start) {
                for(int col = 0; col < C; ++col) {
                    //  we keep compressing all the values from [row_start, col] to this vector and apply kadane
                    pref_col[col] += M[row_start][col];
                }
                maxx = max(maxx, kadane(pref_col));
            }
        }
        
        return maxx;
    }
};


// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<vector<int>> v(N, vector<int>(M));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++) cin >> v[i][j];
        Solution ob;
        cout << ob.maximumSumRectangle(N, M, v) << "\n";
    }
}  // } Driver Code Ends
