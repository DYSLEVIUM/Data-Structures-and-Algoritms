// Time: O(n)
// Space: O(1)
class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      int chunks = 0, maxx = -1;
      for(int i = 0; i < n; ++i) {
        maxx = max(maxx, arr[i]);
        chunks += maxx == i;
      }
      return chunks;
    }
};

// Time: O(n)
// Space: O(n)
class Solution2 {
public:
    int maxChunksToSorted(vector<int>& arr) {
      int n = arr.size();
      
      // in every subarray, if we have all the numbers of the sorted array in the current array, we make it a chunk, i.e., make the smallest valid chunk consequently leading to maximum chunks
      int chunks = 0;
      unordered_map<int, int> fa;
      for(int i = 0; i < n; ++i) {
        ++fa[i], --fa[arr[i]];
        
        if(fa[i] == 0) {
          fa.erase(i);
        }
        
        if(fa[arr[i]] == 0) {
          fa.erase(arr[i]);
        }
        
        chunks += fa.empty();
      }
      return chunks;
    }
};
