class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        
        int lo = 0;
        int hi = rows*cols-1;
        
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            
            //  derive the row and column number from mid
            //  row major
            int rowN = mid/cols;
            int colN = mid%cols;
            
            if(matrix[rowN][colN]==target){
                return true;
            }else if(matrix[rowN][colN]<target)
                lo=mid+1;
            else
                hi=mid-1;
        }
        
        return false;
    }
};
