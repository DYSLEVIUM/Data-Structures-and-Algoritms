class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if(image[sr][sc]==newColor) return image;
        
        vector<vector<int>> ds = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        
        auto checkValidCell = [&image](const int& x, const int& y){
            if(x<0 || x>=image.size() || y<0 || y>=image[0].size()) return false;
            
            return true;
        };
                
        int srcCol = image[sr][sc];
        
        queue<vector<int>> qu;
        qu.push({sr, sc});
        
        while(!qu.empty()){
            vector<int> fr = qu.front();
            qu.pop();
            
            image[fr[0]][fr[1]] = newColor;
            
            for(int i=0;i<ds.size();++i){
                if(checkValidCell(fr[0]+ds[i][0], fr[1]+ds[i][1]) && image[fr[0]+ds[i][0]][fr[1]+ds[i][1]]==srcCol){
                    qu.push({fr[0]+ds[i][0], fr[1]+ds[i][1]});
                }
            }
        }
        
        return image;
    }
};
