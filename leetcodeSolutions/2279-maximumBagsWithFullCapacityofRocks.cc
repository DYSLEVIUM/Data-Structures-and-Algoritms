class Solution {
public:
    int maximumBags(const vector<int> & capacity, const vector<int> & rocks, int additionalRocks) {
        int n = capacity.size();

        vector<int> rem_cap(n);
        for(int i = 0; i < n; ++i) rem_cap[i] = capacity[i] - rocks[i];

        sort(rem_cap.begin(), rem_cap.end());

        int ans = 0;
        while(ans < n && additionalRocks > 0) additionalRocks -= rem_cap[ans++];      
        ans -= additionalRocks < 0; // if my rocks at last are negative, that means the last bag still had some space

        return ans;
    }
};
