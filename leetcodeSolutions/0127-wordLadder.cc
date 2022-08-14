class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
      unordered_set<string> dict(wordList.begin(), wordList.end());
      
      if(!dict.count(endWord)) {
        return 0;
      }
      
      int ans = 1; // including the beginWord
      
      queue<string> qu;
      qu.push(beginWord);
      while(!qu.empty()) {
        int sz = qu.size();
        while(sz--) {
          string curr_word = qu.front();
          qu.pop();
          
          if(curr_word == endWord) {
            return ans;
          }
          
          // trying all positions
          for(int i = 0; i < curr_word.length(); ++i) {
            string temp = curr_word;
            
            // trying all the character changes
            for(char ch = 'a'; ch <= 'z'; ++ch) {
              temp[i] = ch;

              // if this condition is omitted, we may be stuck in a cycle
              if(curr_word == temp) {
                continue;
              }

              // if the word exists in the dictionary
              if(dict.count(temp)) {
                dict.erase(temp); // using this word, so that it isn't used again, also other paths shouldn't take this as even if they did, this current path has an efficient route
                qu.push(temp);
              }
            }
          }
        }
        
        ++ans;
      }
      
      // no possible route
      return 0;
    }
};
