class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
      int rows = bank.size();
      int cols = bank[0].size();
      
      int prev_count = 0;
      for(int col=0;col<cols;++col) prev_count+=bank[0][col] - '0';

      int total_lasers = 0;      
      for(int row=1;row<rows;++row){
        int curr_count = 0;
        
        for(int col=0;col<cols;++col) curr_count += bank[row][col] - '0';
        
        if(!curr_count) continue;
        
        total_lasers += curr_count * prev_count;
        prev_count = curr_count;
      }
      
      return total_lasers;
    }
};
