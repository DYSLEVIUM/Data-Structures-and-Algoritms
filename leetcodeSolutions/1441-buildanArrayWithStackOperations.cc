class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        const string PU = "Push";
        const string PO = "Pop";

        int curr = 1;
        vector<string> ans;
        for(auto &tar : target) {
            while(curr != tar) {
                ans.push_back(PU);
                ans.push_back(PO);
                ++curr;
            }

            ans.push_back(PU);
            ++curr;
        }

        return ans;
    }
};
