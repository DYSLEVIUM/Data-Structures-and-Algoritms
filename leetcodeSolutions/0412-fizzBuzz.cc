class Solution {
public:
    vector<string> fizzBuzz(int n) {
      int cnt_3 = 0, cnt_5 = 0;
      vector<string> ans(n);
      for(int i = 0; i < n; ++i){
        string curr_ans = "";
        ++cnt_3, ++cnt_5;

        if(cnt_3 != 3 && cnt_5 != 5) curr_ans = to_string(i + 1); 
        if(cnt_3 == 3) curr_ans += "Fizz", cnt_3 = 0;
        if(cnt_5 == 5) curr_ans += "Buzz", cnt_5 = 0;
      
        ans[i] = curr_ans;
      }
      
      return ans;
    }
};
