#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

template <typename T> using pbds_set = __gnu_pbds::tree<T, __gnu_pbds::null_type, std::less_equal<T>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update>;  // find_by_order, order_of_key


class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
      //  checking if non-decreasing
      int j=1;
      while(j<n && nums[j-1]<=nums[j]) j++;
      if(j==n) return counts; 

      //  checking if non-increasing and updating as required
      j = n - 2;
      while(j>-1 && nums[j]>=nums[j+1]){
       if(nums[j]>nums[j+1]) counts[j] = n-j-1;
       if(nums[j]==nums[j+1]) counts[j] = counts[j+1];
       --j;
      }
      
      if(j==-1) return counts;
      
      //  pbds implementation
//       pbds_set<int> se;
     
//       int n = nums.size();
//       vector<int> counts(n, 0);
      
//       for(int i = n-1; i>=0; --i) {
//         se.insert(nums[i]);
//         counts[i] = se.order_of_key(nums[i]);
//       }
      
//       return counts;
      
      // bst implementation
      class Node {
       int data;
       Node *left, *right;
       int left_count;

       public:
         Node(int data): data(data), left(nullptr), right(nullptr), left_count(0) {}

         int insert(int key) {
           Node *node = this;
           Node *ri = nullptr;
           int cnt = 0;

           while(node){
             ri = node;
             if(node->data >= key){
               ++node->left_count;
               node = node->left;
             }else{
               cnt += 1 + node->left_count;
               node = node->right;
             }
           }

           Node *pos = new Node(key);
           if(pos->data <= ri->data) ri->left = pos;
           else ri->right = pos;

           return cnt;
         }
      };

      int n = nums.size();
      vector<int> counts(n, 0);
      
      Node* bst = new Node(nums[n-1]);
      for(int i=n-2;i>=0;--i) counts[i] = bst->insert(nums[i]);
      
      return counts;
    }
};
