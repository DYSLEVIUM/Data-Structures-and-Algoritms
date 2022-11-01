class Solution {
public:
    string entityParser(string text) {
        int n = text.size();
        unordered_map<string, string> mp{
            {"&quot;", "\""},
            {"&apos;", "'"},
            {"&amp;", "&"},
            {"&gt;", ">"},
            {"&lt;", "<"},
            {"&frasl;", "/"}
        };

        string ans;
        for(int i = 0; i < n; ++i) {
            string curr;
            if(text[i] == '&') {
                int j = i;
                while(j < n && text[j] != ';') curr += text[j++];
                curr += text[j];

                if(mp.count(curr)) i = j, curr = mp[curr];
                else curr = text[i];
            } else curr = text[i];
            ans += curr;
        }

        return ans;
    }
};
