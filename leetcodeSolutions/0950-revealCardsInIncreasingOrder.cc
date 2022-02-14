class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
      int n = deck.size();
    
      sort(deck.begin(), deck.end());
      deque<int> res;
      
      int ptr = n-1;
      res.push_back(deck[ptr--]);
      
      //  reverse emgineering the solution
      while(ptr>=0){
        //  put last element to front
        res.push_front(res.back());
        res.pop_back();
        
        //  insert new number to front
        res.push_front(deck[ptr--]);
      }
      
      return vector<int>(res.begin(), res.end());
    }
};
