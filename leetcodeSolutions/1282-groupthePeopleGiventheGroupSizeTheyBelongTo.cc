class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        map<int, vector<int>> mp;
        
        for(int i=0;i<groupSizes.size();++i) mp[groupSizes[i]].push_back(i);
        
        vector<vector<int>> ans;
        
        for(auto it = mp.begin(); it!=mp.end();++it){
            int sz = it->first;
            vector<int> vec = it->second;
            
            vector<int> currAns(sz);
            int taken = 0;
            for(int i=0;i<vec.size();++i){
                currAns[taken] = vec[i];
                
                ++taken;
                
                if(taken==sz){
                    ans.push_back(currAns);
                    taken=0;
                }
            }
        }
        
        return ans;
    }
};
