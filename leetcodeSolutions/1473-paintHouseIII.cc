class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
//       const int INF = 1000001;
//       using VI = vector<int>;
//       vector<vector<VI>> dp(m, vector<VI>(target + 1, VI(n, INF)));
   
//       // initialize for house 0, neighborhood will be 1
//       for(int color = 0; color < n; ++color) {
//         if(houses[0] - 1 == color) {
//           //  if the house has the same color, no cost
//           dp[0][1][color] = 0;
//         } else if(!houses[0]) {
//           //  assigninng corresponding cost
//           dp[0][1][color] = cost[0][color];
//         }
//       }
      
//       for(int house = 1; house < m; ++house) {
//         for(int neighbourhoods = 1; neighbourhoods < min(target, house + 1) + 1; ++neighbourhoods) {
//           for(int color = 0; color < n; ++color) {
//             if(houses[house] && color != houses[house] - 1) {
//               //  cannot be painted with different color
//               continue;
//             }
            
//             int curr_cost = INF;
//             //  iterate over all the possible color for previous house
//             for(int prev_color = 0; prev_color < n; ++prev_color) {
//               if(prev_color != color) {
//                 //  decrement the neighbourhood as adjacent houses has different color
//                 curr_cost = min(curr_cost, dp[house - 1][neighbourhoods - 1][prev_color]);
//               } else {
//                 //  previouse house has the same color, no change in neighbourhood count
//                 curr_cost = min(curr_cost, dp[house - 1][neighbourhoods][color]);
//               }
//             }
            
//             int cost_to_paint = houses[house] ? 0 : cost[house][color];
//             dp[house][neighbourhoods][color] = curr_cost + cost_to_paint;
//           }
//         }
//       }
      
//       int min_cost = INF;
//       for(int color = 0; color < n; ++color) {
//         min_cost = min(min_cost, dp[m - 1][target][color]);
//       }
      
//       return min_cost == INF ? -1 : min_cost;
      
      const int INF = 1000001;
      using VI = vector<int>;
      vector<VI> prev(target + 1, VI(n, INF));
      
      // initialize for house 0, neighborhood will be 1
      for(int color = 0; color < n; ++color) {
        if(houses[0] - 1 == color) {
          //  if the house has the same color, no cost
          prev[1][color] = 0;
        } else if(!houses[0]) {
          //  assigninng corresponding cost
          prev[1][color] = cost[0][color];
        }
      }
      
      for(int house = 1; house < m; ++house) {
        vector<VI> curr(target + 1, VI(n, INF));
        
        for(int neighbourhoods = 1; neighbourhoods < min(target, house + 1) + 1; ++neighbourhoods) {
          for(int color = 0; color < n; ++color) {
            if(houses[house] && color != houses[house] - 1) {
              //  cannot be painted with different color
              continue;
            }
            
            int curr_cost = INF;
            //  iterate over all the possible color for previous house
            for(int prev_color = 0; prev_color < n; ++prev_color) {
              if(prev_color != color) {
                //  decrement the neighbourhood as adjacent houses has different color
                curr_cost = min(curr_cost, prev[neighbourhoods - 1][prev_color]);
              } else {
                //  previouse house has the same color, no change in neighbourhood count
                curr_cost = min(curr_cost, prev[neighbourhoods][color]);
              }
            }
            
            int cost_to_paint = houses[house] ? 0 : cost[house][color];
            curr[neighbourhoods][color] = curr_cost + cost_to_paint;
          }
        }
        
        prev = curr;
      }
      
      int min_cost = INF;
      for(int color = 0; color < n; ++color) {
        min_cost = min(min_cost, prev[target][color]);
      }
      
      return min_cost == INF ? -1 : min_cost;
    }
};
