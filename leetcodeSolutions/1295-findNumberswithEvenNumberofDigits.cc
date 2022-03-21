class Solution {
public:
    int findNumbers(vector<int>& nums) {
      int cnt = 0;
      for(int& num: nums) cnt += int(floor((log10(num)) + 1)) % 2 == 0;
      return cnt;
    }
};
