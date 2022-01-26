class Solution {
public:
    vector<int> getRow(int rowIndex) {
      vector<int> res(1,1);
      
      if(rowIndex==0) return res;
      
      res.push_back(1);
      
      for(int i=1;i<rowIndex;++i){
        vector<int> current_row(1,1);
        
        int n = res.size();
        for(int i=1;i<n;++i) current_row.push_back(res[i-1]+res[i]);
        
        current_row.push_back(1);
        res = current_row;
      }
      
      return res;
    }
};
