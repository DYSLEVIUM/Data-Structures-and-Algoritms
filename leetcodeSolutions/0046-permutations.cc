class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        
        auto allPerm = [&ans](const auto& allPerm, vector<int> currNums, deque<int> others){
            if(others.size()==1) {
                currNums.push_back(others[0]);
                ans.push_back(currNums);
                return;
            }
            
            int otherSz = others.size();
            
            currNums.push_back(-1);
            
            for(int i = 0;i<otherSz;++i){
                int first = others[0];
                others.pop_front();
                
                currNums[currNums.size()-1] = first;
                
                allPerm(allPerm, currNums, others);
                
                others.push_back(first);
            }
        };
        
        allPerm(allPerm, vector<int>(0), deque<int>(nums.begin(), nums.end()));
        
        return ans;
    }
};
