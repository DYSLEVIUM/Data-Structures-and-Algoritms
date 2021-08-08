// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
// UNASSIGNED is used for empty cells in sudoku grid 
#define UNASSIGNED 0  

// N is used for the size of Sudoku grid.  
// Size will be NxN  
#define N 9  


 // } Driver Code Ends

class Solution 
{
    public:
    //Function to find a solved Sudoku.
    bool canPlace(int grid[N][N], int row, int col, int x){
        //  row and column check
        for(int i=0;i<N;++i) if(grid[i][col]==x || grid[row][i]==x) return false;
        
        //  small box check
        int smallRow = row - row%3;
        int smallCol = col - col%3;
        
        for(int i=smallRow; i<smallRow+3;++i){
            for(int j=smallCol; j<smallCol+3;++j){
                if(grid[i][j]==x) return false;
            }
        }
        
        return true;
    }
    
    bool canSolve(int grid[N][N], int row, int col){
        if(row==N) return true;
        
        if(col==N) return canSolve(grid, row+1, 0);
        
        if(grid[row][col]!=0) return canSolve(grid, row, col+1);
        
        for(int i=0;i<N;++i){
            if(canPlace(grid, row, col, i+1)){
                grid[row][col] = i+1;
                
                if(canSolve(grid, row, col+1)) return true;
                
                grid[row][col] = 0;
            }
        }
        
        return false;
    }
    
    
    bool SolveSudoku(int grid[N][N])  
    { 
        // Your code here
        if(canSolve(grid, 0, 0)) return true;
        
        return false;
    }
    
    //Function to print grids of the Sudoku.
    void printGrid (int grid[N][N]) 
    {
        // Your code here 
        for(int i=0;i<N;++i) for(int j=0;j<N;++j) cout<<grid[i][j]<<' ';
    }
};

// { Driver Code Starts.

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int grid[N][N];
		
		for(int i=0;i<9;i++)
		    for(int j=0;j<9;j++)
		        cin>>grid[i][j];
		        
		Solution ob;
		
		if (ob.SolveSudoku(grid) == true)  
            ob.printGrid(grid);  
        else
            cout << "No solution exists";  
        
        cout<<endl;
	}
	
	return 0;
}  // } Driver Code Ends
