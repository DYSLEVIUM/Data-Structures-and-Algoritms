class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
      auto binary_search = [&numbers](int lo, int hi, const int& find_val){
        while(lo<=hi){
          int mid = lo+(hi-lo)/2;
          if(numbers[mid]==find_val) return mid;
          else if(numbers[mid]>find_val) hi = mid-1;
          else lo = mid+1;
        }
        return 0;
      };

      int n = numbers.size();
      for(int i=0;i<n;++i){
        int idx = binary_search(i+1, n-1, target-numbers[i]);
        if(idx) return vector<int>{i+1, idx+1};
      }
      
      return vector<int>{-1, -1}; //  unreachable code if it is guaranteed that the pair exists
    }
};
