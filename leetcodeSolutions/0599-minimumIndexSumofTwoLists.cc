class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        int n1 = list1.size(), n2 = list2.size();
        if(n1 > n2) {
            swap(list1, list2);
            swap(n1, n2);
        }
        
        unordered_map<string, int> mp;        
        for(int i = 0; i < n1; ++i) {
            mp[list1[i]] = i;
        }
        
        int minn = INT_MAX;
        for(int i = 0; i < n2; ++i) {
            if(mp.find(list2[i]) != mp.end()) {
                minn = min(minn, i + mp[list2[i]]);
            }
        }
        
        vector<string> ans;
        for(int i = 0; i < n2; ++i) {
            if(mp.find(list2[i]) != mp.end() && minn == i + mp[list2[i]]) {
                ans.push_back(list2[i]);
            }
        }
        
        return ans;
    }
};
