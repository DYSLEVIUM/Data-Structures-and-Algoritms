//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<vector<int>> nQueen(int n) {
        vector<vector<int>> ans;
        
        auto can_place = [&n](const vector<vector<int>> &curr_mat, const int &row, const int &col){
            
            // same col
            for(int i = 0; i < n; ++i) {
                if(curr_mat[i][col]) {
                    return false;
                }
            }
            
            // left-diagonal
            int st_row = row, st_col = col;
            while(st_row >= 0 && st_col >= 0) {
                if(curr_mat[st_row][st_col]) {
                    return false;
                }
                
                --st_row, --st_col;
            }
            
            // right-diagonal
            st_row = row, st_col = col;
            while(st_row >= 0 && st_col < n) {
                if(curr_mat[st_row][st_col]) {
                    return false;
                }
                
                --st_row, ++st_col;
            }
            
            return true;
        };
        
        auto solve = [&](const auto &solve, const int &row, vector<vector<int>> &curr_mat, vector<int> &curr_ans) -> void {
            if(row == n) {
                ans.push_back(curr_ans);
                return;
            }
            
            for(int i = 0; i < n; ++i) {
                if(can_place(curr_mat, row, i)) {
                    curr_ans.push_back(i + 1);
                    curr_mat[row][i] = 1;
                    
                    solve(solve, row + 1, curr_mat, curr_ans);
                    
                    curr_mat[row][i] = 0;
                    curr_ans.pop_back();
                }
            }
        };
        
        vector<vector<int>> curr_mat(n, vector<int>(n));
        vector<int> curr_ans;
        solve(solve, 0, curr_mat, curr_ans);
        
        return ans;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
}
// } Driver Code Ends
