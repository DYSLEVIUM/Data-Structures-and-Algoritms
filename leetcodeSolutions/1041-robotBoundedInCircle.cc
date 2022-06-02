class Solution {
public:
    bool isRobotBounded(string instructions) {
        pair<int, int> pos = {0, 0};    //  position vector
        pair<int, int> dir = {0, 1};    //  direction unit vector
        
        for(char &instruction: instructions) {
            if(instruction == 'G') {
                pos.first += dir.first;
                pos.second += dir.second;
            } 
            //  we will rotate the plane w.r.t the robot
            else if(instruction == 'L') {
                //  when we rotate the robot left, the +x becomes, -y, and, +y becomes +x
                swap(dir.first, dir.second);
                dir.first *= -1;
            } else {
                //  when we rotate the robot right, the +x becomes, +y, and, +y becomes -x
                swap(dir.first, dir.second);
                dir.second *= -1;
            }
        }
        
        //  if position has not been changed or the direction(independent of position) changed, we have a cycle
        return (pos == make_pair(0, 0) || dir != make_pair(0, 1));
    }
};
