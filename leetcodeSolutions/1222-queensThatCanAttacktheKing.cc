class Solution {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        constexpr int BOARD_SIZE = 8;
        vector<vector<int>> board(BOARD_SIZE, vector<int>(BOARD_SIZE));
        for(auto &queen: queens) {
            board[queen[0]][queen[1]] = 1;
        }

        vector<vector<int>> ans;
        for(int dy = -1; dy <= 1; ++dy) {
            for(int dx = -1; dx <= 1; ++dx) {
                if(!dy && !dx) {
                    continue;
                }

                for(int row = king[0] + dy, col = king[1] + dx; 
                    row >= 0 && col >= 0 && row < BOARD_SIZE && col < BOARD_SIZE; 
                    row += dy, col += dx) {
                        if(board[row][col]) {
                            ans.push_back({row, col});
                            break;
                        }
                    }
            }
        }

        return ans;
    }
};
