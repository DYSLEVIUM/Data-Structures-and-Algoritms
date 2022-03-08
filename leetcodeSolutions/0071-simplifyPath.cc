class Solution {
public:
    string simplifyPath(string path) {
      vector<string> directories;
      for(int i = 0; i < path.length(); ++i){
        if(path[i] == '/'){
          ++i;
          string temp = "";
          while(i < path.length() && path[i] != '/'){
            temp += path[i++];
          }

          if(temp != "." && !temp.empty()){
            if(temp == "..") {
              if(!directories.empty()) directories.pop_back(); 
            } else directories.push_back(temp);
          }
          --i;
        }
      }
      
      string new_str = "/";
      for(string& directory: directories) new_str += directory + "/";
      if(new_str.length() > 1) new_str.pop_back(); //  removing the last /
      
      return new_str;
    }
};
