class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
      unordered_set<int> se;
      for(int i = 0; i < arr.size(); ++i) {
        if(se.find(2 * arr[i]) != se.end()) return true;
        if(ceil(1.0 * arr[i] / 2) == floor(1.0 * arr[i] / 2) && se.find(arr[i] / 2) != se.end()) return true;
        se.insert(arr[i]);
      }
      
      return false;
    }
};
