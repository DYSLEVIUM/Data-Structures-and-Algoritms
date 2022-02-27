class Solution {
public:
    bool isHappy(int n) {
      if(n == 1) return true;
      if(se.find(n) != se.end()) return false;
      se.insert(n);
      
      int new_num = 0;
      while(n){
        int rem = n % 10;
        new_num += rem * rem;
        n /= 10;
      }
      
      return isHappy(new_num);
    }
private:
  unordered_set<int> se;
};
