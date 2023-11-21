#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace __gnu_pbds;
  
template<class T> using ordered_set = tree<T, null_type, less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
  
class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        cin.tie(nullptr)->sync_with_stdio(false);

        int n = nums1.size();

        long long ans = 0;
        ordered_set<int> se;
        for(int i = 0; i < n; ++i) {
            int key = nums1[i] - nums2[i];

            ans += se.order_of_key(key + diff + 1);

            se.insert(key);
        }

        return ans;
    }
};
