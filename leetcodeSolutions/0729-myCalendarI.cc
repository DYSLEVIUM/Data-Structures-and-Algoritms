// class MyCalendar {
// public:
//     MyCalendar() {}
    
//     bool book(int start, int end) {
//         for(auto &[st, ed] : bookings) {
//             if(start < ed && st < end) {
//                 return false;
//             }
//         }
        
//         bookings[start] = end;
        
//         return true;
//     }
    
// private:
//     unordered_map<int, int> bookings;
// };

class MyCalendar {
public:
    MyCalendar() {}
    
    bool book(int start, int end) {
        auto slot = bookings.lower_bound({start, end});
        
        if(slot != bookings.end() && slot->first < end ||      // a booked slot with nearest starting after s1 should also have its end after e1  => similar to case-1 
            slot != bookings.begin() && prev(slot)->second > start) {
            return false;
        }
        
        bookings.insert({ start, end });
        return true;
    }
    
private:
    set<pair<int, int>> bookings;
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */
