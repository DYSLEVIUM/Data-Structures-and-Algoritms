class Solution {
public:
    vector<vector<int>> generate(int numRows) {
      vector<vector<int>> res;
      res.push_back(vector<int>(1,1));
      
      if(numRows==1) return res;
      
      res.push_back(vector<int>(2,1));
      
      for(int i=2;i<numRows;++i){
        vector<int> get_prev_row = res[i-1];
        
        vector<int> current_row;
        current_row.push_back(1);
        
        int n = get_prev_row.size();
        for(int i=1;i<n;++i){
          current_row.push_back(get_prev_row[i-1]+get_prev_row[i]);
        }
        
        current_row.push_back(1);
        res.push_back(current_row);
      }
      
      return res;
    }
};
