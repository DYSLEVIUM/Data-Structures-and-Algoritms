class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j=height.size()-1,area = 0;
        
        while(i<j){
            area = max(area, min(height[i],height[j])*(j-i));
            
            //  geedily taking the largest height for the container
            if(height[i]<height[j]) ++i;
            else --j;
        }
        
        return area;
    }
};
