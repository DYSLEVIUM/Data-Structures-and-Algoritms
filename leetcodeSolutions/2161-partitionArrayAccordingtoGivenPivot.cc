class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
    //  O(n) space, O(nlogn) time 
    //  int n = nums.size();
    //  
    //  vector<pair<int,int>> te(n);
    //  for(int i=0;i<n;++i) te[i] = {nums[i], i};
    //  
    //  sort(te.begin(), te.end());
    //  
    //  int l_ptr = 0;
    //  while(te[l_ptr].first!=pivot) ++l_ptr;
    //  
    //  int r_ptr = l_ptr+1;
    //  while(r_ptr<n && te[r_ptr].first==pivot) ++r_ptr;
    //  
    //  sort(te.begin(), te.begin() + l_ptr, [](pair<int, int> a, pair<int, int> b){
    //    return a.second<b.second;
    //  });
    // 
    //  sort(te.begin() + r_ptr, te.end(), [](pair<int, int> a, pair<int, int> b){
    //    return a.second<b.second;
    //  });
    //  
    //  vector<int> res;
    //  for(auto& t: te) res.push_back(t.first);
    //  
    //  return res;
        
    //  O(n) space, O(n) time 
        int less = 0, equal = 0;

        for(int& num: nums){
          less += num < pivot;
          equal += num == pivot;
        }
      
        int low = 0, same = less, high = less+equal;
     
        int n = nums.size();
        vector<int> res(n);
        for(int& num: nums){
          if(num<pivot) res[low++] = num;
          else if(num==pivot) res[same++] = num;
          else res[high++] = num;
        }
      
        return res;
    }
};
