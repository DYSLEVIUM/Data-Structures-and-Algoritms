class Solution {
public:
    string numberToWords(int num) {
      map<int, string> mp{
        // Magnitudes
        {1e9, "Billion"}, {1e6,"Million"}, {1e3, "Thousand"}, {100, "Hundred"}, 
        // Tens
        {90, "Ninety"}, {80, "Eighty"}, {70, "Seventy"}, {60, "Sixty"}, {50, "Fifty"}, {40, "Forty"}, {30, "Thirty"}, {20, "Twenty"}, {10, "Ten"}, 
        // Teens
        {19, "Nineteen"}, {18, "Eighteen"}, {17, "Seventeen"}, {16, "Sixteen"}, {15, "Fifteen"}, {14, "Fourteen"}, {13, "Thirteen"}, {12, "Twelve"}, {11, "Eleven"}, 
        // Ones
        {9, "Nine"}, {8, "Eight"}, {7, "Seven"}, {6, "Six"}, {5, "Five"}, {4, "Four"}, {3, "Three"}, {2, "Two"}, {1, "One"}, {0, "Zero"}
      };
      
      if(num <= 20) return mp[num];
      
      string pre = "", suf = "";
      auto it = mp.upper_bound(num);
      --it;
      
      if(it->first >= 100) pre = numberToWords(num / it->first) + " ";
      
      if(num%it->first != 0) suf = " " + numberToWords(num % it->first);
      
      return pre + it->second + suf;
    }
};
