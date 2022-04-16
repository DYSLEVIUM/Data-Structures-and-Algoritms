class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
      if(cost1 > cost2) swap(cost1, cost2);
      
      //  if we buy cnt_1 of one object, we can use rest money to buy cnt_2 pens; we add 1 to include 0 of second object
      long long ans = 0;
      for(long long cnt_1 = 0; cnt_1 * cost_1 <= total; ++cnt_1) {
        ans += (total - cost1 * cnt_1) / cost2 + 1;
      }
      
      return ans;
    }
};
