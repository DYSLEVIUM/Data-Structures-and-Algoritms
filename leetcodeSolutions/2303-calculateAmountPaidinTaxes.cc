class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
      double tax = 0;
      int prev = 0;
      for(vector<int> &bracket: brackets) {
        if(income >= bracket[0]) {
          tax += 1.0 * (bracket[0] - prev) * bracket[1] / 100;
        } else {
          tax += max(0.0, 1.0 * (income - prev) * bracket[1] / 100);
        }
        prev = bracket[0];
      }
      
      return tax;
    }
};
