class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int delta = 0;
        
        for(int i=0;i<operations.size();++i){
            for(int j=0;j<operations[i].size();++j){
                if(operations[i][j]=='+') {
                    ++delta;
                    break;
                }
                
                if(operations[i][j]=='-'){
                    --delta;
                    break;
                }
            }
        }
        
        return delta;
    }
};
