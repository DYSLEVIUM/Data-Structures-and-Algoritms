class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
      vector<string> letter_morse_mapper = {
        ".-","-...","-.-.","-..",".",
        "..-.","--.","....","..",".---",
        "-.-",".-..","--","-.","---",
        ".--.","--.-",".-.","...","-",
        "..-","...-",".--","-..-","-.--","--.."
      };
      
      auto get_morse = [&letter_morse_mapper](const string& word){
        string morse = "";
        for(auto& letter:word) morse+=letter_morse_mapper[letter-'a'];
        return morse;
      };
      
      set<string> se;
      
      for(auto& word:words) se.insert(get_morse(word));
      
      return se.size();
    }
};
