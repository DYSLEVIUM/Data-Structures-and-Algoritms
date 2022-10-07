class MyCalendarThree {
public:
    MyCalendarThree() {
    }

    void update(const int &start, const int &end, const int &left, const int &right, const int &idx) {
        if(start > right || end < left) {
            return ;
        }

        if(left >= start && right <= end) {
            ++lazy[idx];
            ++sgt[idx];
        } else {
            int mid = left + ((right - left) >> 1);

            update(start, end, left, mid, idx * 2);
            update(start, end, mid + 1, right, idx * 2 + 1);

            sgt[idx] = lazy[idx] + max(sgt[idx * 2], sgt[idx * 2 + 1]);
        }
    }
    
    int book(const int &start, const int &end) {
        // segment tree to store the max
        update(start, end - 1, 1, 1e9, 1);
        return sgt[1];
    }

private:
    unordered_map<int, int> sgt;
    unordered_map<int, int> lazy;
};

class MyCalendarThree1 {
public:
    MyCalendarThree1() {
        
    }
    
    int book(int start, int end) {
        ++mp[start];
        --mp[end];

        // sweep-line algorithm (difference array)
        int booked = 0, maxx = 0;
        for(auto &[_, val] : mp) {
            booked += val;
            maxx = max(maxx, booked);
        }

        return maxx;
    }

private:
    map<int, int> mp;
};

/**
 * Your MyCalendarThree object will be instantiated and called as such:
 * MyCalendarThree* obj = new MyCalendarThree();
 * int param_1 = obj->book(start,end);
 */
