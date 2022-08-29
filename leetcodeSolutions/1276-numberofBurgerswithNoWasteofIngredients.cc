class Solution {
public:
    vector<int> numOfBurgers(int tomatoSlices, int cheeseSlices) {
      // 4a + 2b = tomatoSlices, a + b = cheeseSlices ; a = no of jumbo, b = number of small
      // b = cheeseSlices - a
      // 2(2a + b) = tomatoSlices
      // 2(2a + cheeseSlices - a) = tomatoSlices
      // a = tomatoSlices / 2 - cheeseSlices ; tomatoSlices is divisible 2
      // b = 2 * cheeseSlices - tomatoSlices / 2
      
      if(tomatoSlices % 2 == 0 && tomatoSlices >= 2 * cheeseSlices && tomatoSlices <= cheeseSlices * 4) {
        int a = tomatoSlices / 2 - cheeseSlices;
        return {a, cheeseSlices - a};
      }
      
      return {};
    }
};
