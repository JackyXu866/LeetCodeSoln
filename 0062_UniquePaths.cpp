class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> gd(m, vector<int>(n, 0));
        gd[0][0] = 1;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                int tmp = 0;
                if(i-1 >= 0) tmp += gd[i-1][j];
                if(j-1 >= 0) tmp += gd[i][j-1];
                gd[i][j] = max(gd[i][j], tmp);
            }
        }
        
        return gd[m-1][n-1];
    }
};
