class Solution {
public:
    int calPoints(vector<string>& ops) {
      vector<int> val;
      
      for(string& op: ops) {
        if(op == "+") {
          int ff = val.back();
          val.pop_back();
          
          int ss = val.back();
          val.pop_back();
          
          val.push_back(ss);
          val.push_back(ff);
          
          val.push_back(ff + ss);
        } else if (op == "D") {
          int v = val.back();
          
          val.push_back(2 * v);
        } else if (op == "C") {
          val.pop_back();
        } else {
          val.push_back(stoi(op));
        }
      }
      
      return accumulate(val.begin(), val.end(), 0);
    }
};
