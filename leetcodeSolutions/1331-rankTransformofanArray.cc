#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
template <typename T> using pbds_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
      int n = arr.size();
      
//       vector<int> temp = arr;
//       sort(temp.begin(), temp.end());

//       map<int, int> mp;
//       int rank = 1;
//       for(int i = 0; i < n; ++i) {
//         mp[temp[i]] = rank;
//         if(i == n - 1) break;
//         rank += temp[i + 1] != temp[i];
//       }
      
//       vector<int> ans(n);
//       for(int i = 0; i < n; ++i) ans[i] = mp[arr[i]];
      
//       return ans;

      pbds_set<int> se;
      for(int& num: arr) se.insert(num);
      
      vector<int> ans(n);
      for(int i = 0; i < n; ++i) ans[i] = se.order_of_key(arr[i]) + 1;
      
      return ans;
    }
};
