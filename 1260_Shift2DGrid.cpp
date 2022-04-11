class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int s = grid.size()*grid[0].size(), m = grid.size(), n = grid[0].size();
        k = k % s;
        vector<vector<int>> rt(grid.size(), vector<int>(grid[0].size(), 0));
        
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                int tmp = (i*n+j+k+1)%s;
                int r = tmp/n;
                int c = tmp%n-1;
                if(c < 0) c = n-1, r--;
                if(r < 0) r = m-1;
                rt[r][c] = grid[i][j];
            }
        }
        
        return rt;
    }
};
