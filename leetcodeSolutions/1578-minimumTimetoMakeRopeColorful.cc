class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = neededTime.size();

        int ans = 0;
        for(int i = 0; i < n; ++i) {
            int j = i + 1, maxx = neededTime[i], sum = neededTime[i];
            while(j < n && colors[i] == colors[j]) {
                maxx = max(maxx, neededTime[j]);
                sum += neededTime[j++];
            }
            ans += sum - maxx;
            i = j - 1;
        }

        return ans;
    }
};
