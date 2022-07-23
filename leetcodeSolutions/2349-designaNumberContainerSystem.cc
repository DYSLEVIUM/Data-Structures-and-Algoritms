class NumberContainers {
public:
    NumberContainers() {}
    
    void change(int index, int number) {
        if(m_idx_num.find(index) != m_idx_num.end()) {
            //  remove the previous number using the index
            int temp_num = m_idx_num[index];
            if(m_num_idx[temp_num].size() == 1) {
                m_num_idx.erase(temp_num);
            } else {
                m_num_idx[temp_num].erase(index);
            }
        }
        m_idx_num[index] = number;
        m_num_idx[number].insert(index);
    }
    
    int find(int number) {
        if(m_num_idx.find(number) == m_num_idx.end()) {
            return -1;
        }
        
        return *(m_num_idx[number].begin());
    }
private:
    unordered_map<int, int> m_idx_num;
    unordered_map<int, set<int>> m_num_idx;
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */
