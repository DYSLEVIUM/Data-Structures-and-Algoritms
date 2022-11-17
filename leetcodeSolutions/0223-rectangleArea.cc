class Solution {
public:
    int computeArea(int ax1, int ay1, int ax2, int ay2, int bx1, int by1, int bx2, int by2) {
        auto get_area = [](const int & x1, const int & y1, const int & x2, const int & y2){
            return abs(x1 - x2) * abs(y1 - y2);
        };

        int intersecting = 0;
        if(max(ax1, bx1) <= min(ax2, bx2) && max(ay1, by1) <= min(ay2, by2))
            intersecting = get_area(max(ax1, bx1), max(ay1, by1), min(ax2, bx2), min(ay2, by2));
        
        return get_area(ax1, ay1, ax2, ay2) + 
                get_area(bx1, by1, bx2, by2) - 
                intersecting;
    }
};
