class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
      auto get_files = [](const string &path) -> pair<string, vector<string>> {
        vector<string> words;
        
        stringstream ss(path);
        string word;
        while(ss >> word) {
          words.push_back(word);
        }

        reverse(words.begin(), words.end());
        string ppath = words.back();
        words.pop_back();
        
        return {ppath, words};
      };
      
      unordered_map<string, vector<string>> mp;
      for(auto &path : paths) {
        auto [ppath, files] = get_files(path);
        for(auto &file : files) {
          string content = file.substr(file.find_first_of('('), file.find_last_of(')'));
          string ffile = ppath + '/' + file.substr(0, file.find_first_of('('));
          
          // cout << content << ", " << ffile << '\n';
          mp[content].push_back(ffile);
        }
        // cout << '\n';
      }
      
      vector<vector<string>> ans;
      for(auto &[content, files] : mp) {
        vector<string> curr_ans;
        if(files.size() > 1) {
          for(auto &file : files) {
            curr_ans.push_back(file);
          } 
        }
        
        if(!curr_ans.empty()) {
          ans.push_back(curr_ans);
        }
      }
      
      return ans;
    }
};
