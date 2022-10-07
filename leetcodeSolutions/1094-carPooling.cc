class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        // sweep line algorithm
        int dist = 1002;
        vector<int> dist_capacity(dist);
        for(auto &trip : trips) {
            // offset to start from 1
            int nos = trip[0], from = trip[1] + 1, to = trip[2] + 1;
            dist_capacity[from] += nos;
            dist_capacity[to] -= nos;
        }

        for(int i = 1; i < dist; ++i) {
            dist_capacity[i] += dist_capacity[i - 1];
            if(dist_capacity[i] > capacity) {
                return false;
            }
        }

        return true;
    }
};
