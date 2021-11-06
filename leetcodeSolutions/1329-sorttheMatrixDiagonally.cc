class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) {
        int rowSize = mat.size(), colSize = mat[0].size();
        
        //  diagonals at row 0,        
        for(int j=0;j<colSize;++j){
            vector<int> eles;            
            
            int currRow = 0, currCol = j;
            while(currRow<rowSize && currCol<colSize){
                eles.push_back(mat[currRow++][currCol++]);
            }
            
            sort(eles.begin(), eles.end());
            
            int idx=0;
            
            currRow = 0, currCol = j;
            for(int idx=0;idx<eles.size();++idx) mat[currRow++][currCol++]=eles[idx];
        }
        
        //  diagonals at col 0
        for(int i=0;i<rowSize;++i){
            vector<int> eles;            
            
            int currRow = i, currCol = 0;
            while(currRow<rowSize && currCol<colSize){
                eles.push_back(mat[currRow++][currCol++]);
            }
            
            sort(eles.begin(), eles.end());
            
            int idx=0;
            
            currRow = i, currCol = 0;
            for(int idx=0;idx<eles.size();++idx) mat[currRow++][currCol++]=eles[idx];
        }
        
        return mat;
    }
};
