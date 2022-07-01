class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
      sort(boxTypes.begin(), boxTypes.end(), [](const vector<int> &a, const vector<int> &b){
        if(a[1] == b[1]) {
          return a[0] > b[0];
        }
        return a[1] > b[1];
      });
      
      int total_units = 0;
      for(vector<int> &boxType: boxTypes) {
        int numberOfBoxes = boxType[0], numberOfUnitsPerBox = boxType[1];
        
        if(numberOfBoxes <= truckSize) {
          truckSize -= numberOfBoxes;
          total_units += numberOfBoxes * numberOfUnitsPerBox;
        } else {
          total_units += truckSize * numberOfUnitsPerBox;
          break;
        }
      }
      
      return total_units;
    }
};
