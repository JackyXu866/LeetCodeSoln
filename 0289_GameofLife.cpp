class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        m = board.size(), n = board[0].size();
        
        for(uint i = 0; i < m; i++){
            for(uint j = 0; j < n; j++){
                int tmp = findNei(board, i, j);
                if(board[i][j]) board[i][j] = 9+tmp;
                else board[i][j] = -9-tmp;
            }
        }
        
        for(uint i = 0; i < m; i++){
            for(uint j = 0; j < n; j++){
                int tmp = abs(board[i][j])-9;
                if((tmp == 2 || tmp == 3) && board[i][j] > 0) board[i][j] = 1;
                else if(tmp == 3 && board[i][j] < 0) board[i][j] = 1;
                else board[i][j] = 0;
            }
        }
    }
    
private:
    int findNei(vector<vector<int>>& bd, uint i, uint j){
        int rt = 0;
        for(const auto& k : nb){
            if(i+k[0] < m && j+k[1] < n && bd[i+k[0]][j+k[1]] > 0) ++rt;
        }
        return rt;
    }
    
    const int nb[8][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}, {1, 1}, {-1, -1}, {1, -1}, {-1, 1}};
    uint m, n;
};
