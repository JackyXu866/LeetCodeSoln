typedef pair<int, int> pos;
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size()-1;
        if(grid[0][0] == 1) return -1;
        if(grid[n][n] == 1) return -1;
        if(n == 0) return 1;
        
        queue<pos> q;
        q.push({0, 0});
        int rt = 1;
        int dir[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        
        while(!q.empty()){
            int i = q.size();
            rt++;
            for(; i>0; i--){
                auto [x, y] = q.front();
                q.pop();
                
                for(auto& d : dir){
                    int dx = x + d[0], dy = y + d[1];
                    if(dx == n && dy == n) return rt;
                    else if(dx >= 0 && dx <= n && dy >= 0 && dy <= n
                           && grid[dx][dy] == 0){
                        q.push({dx, dy});
                        grid[dx][dy] = -1; // visited
                    }
                }
            }
        }
        
        return -1;
    }
    
};
