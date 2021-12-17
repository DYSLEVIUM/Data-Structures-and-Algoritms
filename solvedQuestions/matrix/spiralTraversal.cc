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
        vector<int> ans;

        //  empty matrix
        if(matrix.size() == 0) return ans;
        
        int rows = matrix.size(), cols = matrix[0].size();
        
        int top = 0, left = 0, bottom = rows - 1, right = cols - 1;
        
        while(top<=bottom && left<=right){
            //  top row
            for(int j=left;j<=right;++j) ans.push_back(matrix[top][j]);
            ++top;
            
            //  checking this condition again as only a single row matrix can exist itself
            if(top>bottom) break;
            
            //  right column
            for(int i=top;i<=bottom;++i) ans.push_back(matrix[i][right]);
            --right;
            
            //  checking this condition again as only a single column matrix can exist itself
            if(left>right) break;
            
            //  bottom row
            for(int j=right;j>=left;--j) ans.push_back(matrix[bottom][j]);
            --bottom;
            
            //  left column
            for(int i=bottom;i>=top;--i) ans.push_back(matrix[i][left]);
            ++left;
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
