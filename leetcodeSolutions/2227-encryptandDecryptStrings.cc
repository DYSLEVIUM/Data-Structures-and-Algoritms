class Encrypter {
public:
    unordered_map<char, string> ch_str;
    unordered_map<string, int> dict_cnt;
    
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        int keys_size = keys.size();
        for(int i = 0; i < keys.size(); ++i) {
            ch_str[keys[i]] = values[i];
        }
        
        for(int i = 0; i < dictionary.size(); ++i) {
            ++dict_cnt[encrypt(dictionary[i])];
        }
    }
    
    string encrypt(string word1) {
        string new_str = "";
        for(auto& ch: word1) {
            new_str += ch_str[ch];
        }
        
        return new_str;
    }
    
    int decrypt(string word2) {
        return dict_cnt[word2];
    }
};

/**
 * Your Encrypter object will be instantiated and called as such:
 * Encrypter* obj = new Encrypter(keys, values, dictionary);
 * string param_1 = obj->encrypt(word1);
 * int param_2 = obj->decrypt(word2);
 */
