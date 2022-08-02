// heap solution
// class Solution {
// public:
//     int kthSmallest(vector<vector<int>>& matrix, int k) {
//       priority_queue<int> maxHeap;
      
//       for(int i=0;i<matrix.size();++i){
//         for(int j=0;j<matrix[i].size();++j){
//           maxHeap.push(matrix[i][j]);
          
//           if(maxHeap.size()>k) maxHeap.pop();
//         }
//       }
      
//       return maxHeap.top();
//     } 
// };

// binary search solution
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int rows = matrix.size(), cols = rows ? matrix[0].size() : 0;
        
        int lo = matrix[0][0], hi = matrix[rows - 1][cols - 1];
        while(lo < hi) {
            int mid = lo + ((hi - lo) >> 1);
            
            int cnt = 0;
            for(int row = 0; row < rows; ++row) {
                if(mid < matrix[row][0]) {
                    continue;
                }
                
                if(mid >= matrix[row][cols - 1]) {
                    cnt += cols;
                    continue;
                }
                
                int lo_i = 0, hi_i = cols - 1;
                while(lo_i < hi_i) {
                    int mid_i = lo_i + ((hi_i - lo_i) >> 1);
                    
                    if(matrix[row][mid_i] <= mid) {
                        lo_i = mid_i + 1;
                    } else {
                        hi_i = mid_i;
                    }
                }
                
                cnt += lo_i;
            }
            
            if(cnt < k) {
                lo = mid + 1;
            } else {
                hi = mid;
            }
        }
        
        return lo;
    }
};
