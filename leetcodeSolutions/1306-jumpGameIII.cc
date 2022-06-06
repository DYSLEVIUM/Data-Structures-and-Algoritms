class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        int n = arr.size();
        unordered_set<int> visited;
        queue<int> qu;
        qu.push(start);
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                int fr = qu.front();
                qu.pop();
                if(fr < 0 || fr >= n || visited.find(fr) != visited.end()) {
                    continue;
                }
                if(!arr[fr]) {
                    return true;
                }
                visited.insert(fr);
                qu.push(fr - arr[fr]);
                qu.push(fr + arr[fr]);
            }
        }
        
        return false;
    }
};
