class Solution {
public:
    vector<int> pancakeSort(vector<int>& arr) {
        vector<int> ans;

        int curr = arr.size() - 1;
        while(curr != -1) {
            int maxx = max_element(arr.begin(), arr.begin() + curr + 1) - arr.begin();
            if(maxx != curr) {
                reverse(arr.begin(), arr.begin() + maxx + 1);
                reverse(arr.begin(), arr.begin() + curr + 1);
                ans.push_back(maxx + 1);
                ans.push_back(curr + 1);
            }
            --curr;
        }

        return ans;
    }
};
