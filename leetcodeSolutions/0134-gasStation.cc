class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        
        for(int i = 0; i < n; ++i) {
            int tank = gas[i], j = i, cnt = 0;
            
            while(tank >= cost[j] && cnt != n) {
                tank = tank - cost[j];
                j = (j + 1) % n;
                tank += gas[j];
                ++cnt;
            }
            
            if(cnt == n) {
                return i;
            }
            
            i = max(i, j - 1);
        }
        
        return -1;
    }
};
