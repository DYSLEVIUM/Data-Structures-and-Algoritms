class Solution {
public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        srand(time(NULL));
        
        string shortUrl = "";
        for(int i = 0; i < m_short_len; ++i) {
            shortUrl += m_char_set[rand() % m_char_set.length()];
        }
        
        m_hashmap[shortUrl] = longUrl;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        return m_hashmap[shortUrl];
    }
private:
    const string m_char_set = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    const int m_short_len = 6;
    unordered_map<string, string> m_hashmap;
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
