class MyCalendarTwo {
public:
    MyCalendarTwo() {
        
    }
    
    bool book(const int &start, const int &end) {
        ++mp[start];
        --mp[end];

        int booked = 0;
        for(auto &[_, val] : mp) {
            booked += val;

            if(booked == 3) {
                --mp[start];
                ++mp[end];

                return false;
            }
        }

        return true;
    }

private:
    map<int, int> mp;
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo* obj = new MyCalendarTwo();
 * bool param_1 = obj->book(start,end);
 */
