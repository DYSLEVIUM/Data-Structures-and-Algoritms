class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
      int n = plants.size();
      
      int curr_capacity = capacity;      
      int steps = 1;
      for(int i = 0; i < n - 1; ++i) {
        ++steps;
        curr_capacity -= plants[i];
        
        //  we can do this because, max(plants[i] <= capacity)
        if(curr_capacity < plants[i + 1]) {
          steps += 2 * (i + 1);
          curr_capacity = capacity;
        }
      }
      
      return steps;
    }
};
