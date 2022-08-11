//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    public:
    vector<string> findPath(vector<vector<int>> &m, int n) {
        vector<string> ans;
        vector<vector<bool>> vis(n, vector<bool>(n));
        vector<tuple<int, int, char>> deltas{make_tuple(-1, 0, 'U'), make_tuple(0, 1, 'R'), 
                                             make_tuple(1, 0, 'D'), make_tuple(0, -1, 'L')};
        auto dfs = [&](const auto &dfs, const int &row, const int &col, const string &curr_ans){
            if(row < 0 || row >= n || col < 0 || col >= n || vis[row][col] || !m[row][col]) {
                return;
            }
            
            if(row == n - 1 && col == n - 1) {
                ans.push_back(curr_ans);
                return;
            }
            
            
            vis[row][col] = true;
            
            for(auto &delta : deltas) {
                int new_row = row + get<0>(delta);
                int new_col = col + get<1>(delta);
                string new_curr_ans = curr_ans + get<2>(delta);
                
                dfs(dfs, new_row, new_col, new_curr_ans);
            }
            
            vis[row][col] = false;
        };
        dfs(dfs, 0, 0, "");
        
        return ans;
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends
