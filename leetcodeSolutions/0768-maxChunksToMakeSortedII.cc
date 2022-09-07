class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      
      vector<int> temp(arr.begin(), arr.end());
      sort(temp.begin(), temp.end());

      int chunks = 0;
      long long sum1 = 0, sum2 = 0;
      for(int i = 0; i < n; ++i) {
        sum1 += temp[i];
        sum2 += arr[i];
        
        chunks += sum1 == sum2;
      }
      
      return chunks;
    }
};

class Solution2 {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      
      vector<int> temp(arr.begin(), arr.end());
      sort(temp.begin(), temp.end());

      int chunks = 0;
      unordered_map<int, int> fa;
      for(int i = 0; i < n; ++i) {
        --fa[temp[i]];
        ++fa[arr[i]];
        
        if(fa[temp[i]] == 0) {
          fa.erase(temp[i]);
        }
        
        if(fa[arr[i]] == 0) {
          fa.erase(arr[i]);
        }
        
        chunks += fa.empty();
      }
      
      return chunks;
    }
};
