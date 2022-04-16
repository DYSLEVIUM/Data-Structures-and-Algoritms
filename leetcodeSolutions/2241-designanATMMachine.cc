class ATM {
public:
    unordered_map<int, long long> notes;
    set<int, greater<int>> valid_notes{500, 200, 100, 50, 20};
    ATM() {
    }
    
    void deposit(vector<int> banknotesCount) {
      int i = 4;
      for(int note: valid_notes) {
        notes[note] += banknotesCount[i--];
      }
    }
    
    vector<int> withdraw(int amount) {
      int i = 4;
      vector<int> ans(5);
      for(int note: valid_notes) {
        long long cnt = amount / note;
        
        amount -= note * min(cnt, notes[note]); //  remaining money
        ans[i--] = min(cnt, notes[note]); //  to widthdraw these notes
        notes[note] -= min(cnt, notes[note]); //  removing from the atm
      }
      
      if(amount) {
        //  we can't give the money, so put it back in the atm
        deposit(ans);
        return { -1 };
      }
      
      return ans;
    }
};

/**
 * Your ATM object will be instantiated and called as such:
 * ATM* obj = new ATM();
 * obj->deposit(banknotesCount);
 * vector<int> param_2 = obj->withdraw(amount);
 */
