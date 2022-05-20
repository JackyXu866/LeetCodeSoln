class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        if(obstacleGrid[0][0] == 1) return 0;
        if(obstacleGrid[m-1][n-1] == 1) return 0;
        vector<vector<int>> gd(m, vector<int>(n, 0));
        gd[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(obstacleGrid[i][j] == 1) continue;
                int tmp = 0;
                if(i-1 >= 0) tmp += gd[i-1][j];
                if(j-1 >= 0) tmp += gd[i][j-1];
                gd[i][j] = max(gd[i][j], tmp);
            }
        }
        
        return gd[m-1][n-1];
    }
};
