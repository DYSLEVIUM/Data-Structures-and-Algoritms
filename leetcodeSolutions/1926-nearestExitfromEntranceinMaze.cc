class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int rows = maze.size(), cols = rows ? maze[0].size() : 0;
        vector<pair<int, int>> deltas{{-1, 0}, {0, -1}, {0, 1}, {1, 0}};

        vector<vector<int>> vis(rows, vector<int>(cols));

        int steps = 0;
        queue<pair<int, int>> qu;
        maze[entrance[0]][entrance[1]] = '+'; // visited
        qu.push({entrance[0], entrance[1]});
        while(!qu.empty()) {
            int sz = qu.size();
            while(sz--) {
                auto &[row, col] = qu.front();

                if(row == 0 || col == 0 || row == rows - 1 || col == cols - 1) {
                    if(maze[row][col] != '+') return steps;
                }
                
                for(auto & [dr, dc] : deltas) {
                    int new_row = row + dr, new_col = col + dc;
                    if(new_row < 0 || new_row == rows || new_col < 0 || new_col == cols || maze[new_row][new_col] == '+' || vis[new_row][new_col]) continue;
                    
                    qu.push({new_row, new_col});
                    vis[new_row][new_col] = 1;
                }
                qu.pop();
            }
            ++steps;
        }

        return -1;
    }
};
