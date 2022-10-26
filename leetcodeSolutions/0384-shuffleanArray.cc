class Solution {
public:
    Solution(vector<int>& nums) {
        m_data.reserve(nums.size());
        m_idx.reserve(nums.size());
        
        for(int i = 0; i < nums.size(); ++i) {
            m_data.push_back(nums[i]);
            m_idx.push_back(i);
        }
    }
    
    vector<int> reset() {
        int i = 0;
        while(i < m_data.size()) {
            // cycle sorting m_idx O(1)
            while(m_idx[i] != i) {
                int pos = m_idx[i];
                swap(m_data[i], m_data[pos]);
                swap(m_idx[i], m_idx[pos]);
            }
            ++i;
        }

        return m_data;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < m_data.size(); ++i) {
            int randd = rand() % m_data.size();
            swap(m_data[i], m_data[randd]);
            swap(m_idx[i], m_idx[randd]);
        }

        return m_data;
    }

private:
    vector<int> m_data, m_idx;
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
