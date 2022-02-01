class Solution {
public:
    string intToRoman(int num) {
      unordered_map<int, string> mp;
      mp[1] = "I";
      mp[5] = "V";
      mp[10] = "X";
      mp[50] = "L";
      mp[100] = "C";
      mp[500] = "D";
      mp[1000] = "M";

      string ans = "";
      int place = 1;  //  number place
      while(num){
        int rem = num % 10;
        
        rem *= place;
        
        while(rem){
          if(mp.find(rem) != mp.end()) ans = mp[rem] + ans, rem = 0;  //  if the digit is present in the map
          else if(mp.find(rem + place) != mp.end()) ans = mp[place] + mp[rem + place] + ans, rem = 0; //  if succedding element is possible
          else ans = mp[place] + ans, rem -= place; //  if none works out, only the preceding element can be taken
        }
        
        num /= 10;
        place *= 10;
      }

      return ans;
    }
};
