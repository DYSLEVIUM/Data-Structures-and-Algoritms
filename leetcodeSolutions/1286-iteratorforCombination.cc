class CombinationIterator {
public:
    CombinationIterator(string characters, int combinationLength) {
        m_comb.reserve(1 << characters.size());
        for(int i = 0; i < (1 << characters.size()); ++i) {
            string s;
            int mask = i, iter = 0;
            while(mask) {
                if(mask & 1) s += characters[iter];
                mask >>= 1;
                ++iter;
            }
            if(s.length() == combinationLength) m_comb.push_back(s);
        }
        sort(m_comb.begin(), m_comb.end());
    }
    
    string next() {
        return m_comb[m_curr++];
    }
    
    bool hasNext() {
        return m_curr < m_comb.size();
    }

private:
    vector<string> m_comb;
    int m_curr = 0;
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
