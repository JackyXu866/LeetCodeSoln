typedef tuple<int, int, int> tile;    // {weight, x, y}

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int row = heights.size(), col = heights[0].size();
        
        vector<vector<int>> weight(row, vector<int>(col, INT_MAX));
        priority_queue< tile, vector<tile>, greater<tile> > q;
        
        weight[0][0] = 0;
        q.push({0, 0, 0});
        
        while(!q.empty()){
            auto [w, x, y] = q.top();
            q.pop();
            
            if(weight[x][y] < w) continue;  // no need to update
            if(x == row-1 && y == col-1) return w;  // goal
            
            for(auto [dx, dy] : dir){
                int tmpx = x + dx, tmpy = y + dy;
                // in bound verification
                if(tmpx < 0 || tmpx >= row) continue;
                if(tmpy < 0 || tmpy >= col) continue;
                
                int tmpw = max(w, abs(heights[x][y]-heights[tmpx][tmpy]));
                if(tmpw < weight[tmpx][tmpy]){
                    weight[tmpx][tmpy] = tmpw;
                    q.push({tmpw, tmpx, tmpy});
                }
            }
        }
        
        return -1;
    }
};
