class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        int n = names.size();

        vector<pair<int, string>> arr(n);
        for(int i = 0; i < n; ++i) {
            arr[i] = { heights[i], names[i] };
        }

        sort(arr.rbegin(), arr.rend());

        for(int i = 0; i < n; ++i) {
            names[i] = arr[i].second;
        }

        return names;
    }
};
