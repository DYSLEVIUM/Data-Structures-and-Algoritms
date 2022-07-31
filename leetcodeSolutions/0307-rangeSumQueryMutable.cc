class NumArray {
public:
    NumArray(vector<int>& nums) : m_n(nums.size()) {
        m_st.resize(4 * m_n);
        build_st(0, 0, m_n - 1, nums);
    }
    
    void update(int index, int val) {
        update_st(0, 0, m_n - 1, index, val);
    }
    
    int sumRange(int left, int right) {
        return range_sum(0, 0, m_n - 1, left, right);
    }
private:
    int m_n;
    vector<int> m_st;
    
    void build_st(const int &idx, const int &lo, const int &hi, const vector<int> &nums) {
        if(lo == hi) {
            m_st[idx] = nums[lo];
            return;
        }
        
        int mid = lo + ((hi - lo) >> 1);
        
        build_st(2 * idx + 1, lo, mid, nums);
        build_st(2 * idx + 2, mid + 1, hi, nums);
        
        m_st[idx] = m_st[2 * idx + 1] + m_st[2 * idx + 2];
    }
    
    void update_st(const int &idx, const int &lo, const int &hi, const int &index, const int &val){
        if(lo == hi) {
            m_st[idx] = val;
            return;
        }
        
        int mid = lo + ((hi - lo) >> 1);
        
        if(index <= mid) {
            update_st(2 * idx + 1, lo, mid, index, val);
        } else {
            update_st(2 * idx + 2, mid + 1, hi, index, val);
        }
        
        m_st[idx] = m_st[2 * idx + 1] + m_st[2 * idx + 2];
    }
    
    int range_sum(const int &idx, const int &lo, const int &hi, const int &left, const int &right) {
        if(lo >= left && right >= hi) {
            return m_st[idx];
        }
        
        if(lo > right || hi < left) {
            return 0;
        }
        
        int mid = lo + ((hi - lo) >> 1);
        
        return range_sum(2 * idx + 1, lo, mid, left, right) + range_sum(2 * idx + 2, mid + 1, hi, left, right);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */
