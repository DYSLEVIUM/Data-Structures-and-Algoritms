class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        cin.tie(nullptr)->sync_with_stdio(false);

        auto check = [&nums](const int & le, const int & ri){
            const auto & [minn, maxx] = minmax_element(nums.begin() + le, nums.begin() + ri + 1);

            if(*maxx == *minn) { // all elements are same
                return true;
            }

            int sz = ri - le + 1;
            if((*maxx - *minn) % (sz - 1)) { // (al - a1) = a + (n - 1)d - a = (n - 1)d => (al - a1) % d === 0; checking for enough elements
                return false;
            }

            unordered_set<int> se;
            int d = (*maxx - *minn) / (sz - 1);
            for(int i = le; i <= ri; ++i) {
                if((nums[i] - *minn) % d) {
                    return false;
                }

                int pos = ((nums[i] - *minn) / d);
                if(se.count(pos)) {
                    return false;
                }
                se.insert(pos);
            }

            return true;
        };

        int m = l.size();
        vector<bool> ans(m);
        for(int i = 0; i < m; ++i) {
            ans[i] = check(l[i], r[i]);
        }

        return ans;
    }
};
