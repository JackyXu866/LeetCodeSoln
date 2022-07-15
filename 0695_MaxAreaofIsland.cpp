class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int rt = 0;
        for(int m = 0; m < grid.size(); m++){
            for(int n = 0; n < grid[0].size(); n++){
                if(grid[m][n] == 0 || grid[m][n] == -1) continue;
                int s = 0;
                recur(grid, m, n, s);
                rt = max(rt, s);
            }
        }
        
        return rt;
    }
    
private:
    void recur(vector<vector<int>>& grid, int m, int n, int& s){
        if(m < 0 || n < 0 || m >= grid.size() || n >= grid[0].size() ||
           grid[m][n] == 0 || grid[m][n] == -1) return;
        
        s++;
        grid[m][n] = -1;
        recur(grid, m-1, n, s);
        recur(grid, m, n-1, s);
        recur(grid, m+1, n, s);
        recur(grid, m, n+1, s);
    }
};
