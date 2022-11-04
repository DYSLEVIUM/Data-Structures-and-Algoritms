class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n = arr.size();
        
        sort(arr.begin(), arr.end(), [&](const int & a, const int & b){
            int aabs = abs(a - x), babs = abs(b - x);
            if(aabs == babs) return a < b;
            return aabs < babs;
        });

        vector<int> ans = vector<int>(arr.begin(), arr.begin() + k);
        sort(ans.begin(), ans.end());
        
        return ans;
    }
};
