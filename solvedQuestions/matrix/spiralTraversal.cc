// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{   
    public: 
    //Function to return a list of integers denoting spiral traversal of matrix.
    vector<int> spirallyTraverse(vector<vector<int> > matrix, int r, int c) 
    {
        // code here
        vector<int> ans;
        
        int row = 0, col = 0;
        
        while(row<r && col<c){
            //  print first row
            for(int j=col;j<c;++j) ans.push_back(matrix[row][j]);
            ++row;
            
            // print the last column
            for(int i=row;i<r;++i) ans.push_back(matrix[i][c-1]);
            --c;
            
            // print the last row from the remaining rows
            if(row < r){
                for(int j=c-1;j>=col;--j) ans.push_back(matrix[r-1][j]);
                --r;
            }
            
            //  print the first column from the remaining columns
            if (col < c) {
                for (int i = r - 1; i >= row; --i) ans.push_back(matrix[i][col]);
                ++col;
            }
        }
    
        return ans;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--) 
    {
        int r,c;
        cin>>r>>c;
        vector<vector<int> > matrix(r); 

        for(int i=0; i<r; i++)
        {
            matrix[i].assign(c, 0);
            for( int j=0; j<c; j++)
            {
                cin>>matrix[i][j];
            }
        }

        Solution ob;
        vector<int> result = ob.spirallyTraverse(matrix, r, c);
        for (int i = 0; i < result.size(); ++i)
                cout<<result[i]<<" ";
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends
