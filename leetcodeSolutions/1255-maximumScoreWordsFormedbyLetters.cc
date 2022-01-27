class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
      vector<int> valid_letters_fa(26, 0);
      for(auto& letter: letters) ++valid_letters_fa[letter-'a'];
    
      auto get_score = [&valid_letters_fa, &score](const vector<string>& curr_words){
        //  check if we can take all the words
        vector<int> temp_valid_letters_fa = valid_letters_fa;
        for(auto& word: curr_words){
          for(auto& letter: word){
            if(temp_valid_letters_fa[letter-'a']==0) return INT_MIN;
            else --temp_valid_letters_fa[letter-'a'];
          }
        }
        
        //  calculate the score
        int curr_score = 0;
        for(auto& word: curr_words){
          for(auto& letter: word){
            curr_score += score[letter-'a'];
          }
        }
        
        return curr_score;
      };
      
      int n = words.size();
      int maxi = INT_MIN;
      int max_mask = (1<<n);
      for(int i=0;i<max_mask;++i){
        int mask = i;
        int iter = 0;
        vector<string> curr_words;
        while(mask){
          if(mask&1) curr_words.push_back(words[iter]); 
          ++iter;
          mask>>=1;
        }
        
        maxi = max(maxi, get_score(curr_words));
      }
      
      return maxi;
    }
};
