class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int rt = 0;
        m = matrix.size(), n = matrix[0].size();
        for(int x=0; x < m; x++){
            for(int y=0; y < n; y++){
                rt = max(rt, recur(matrix, x, y, -1));
            }
        }
        
        return rt;
    }
    
private:
    int m, n;
    int dp[200][200];
    
    int recur(vector<vector<int>>& matrix, int x, int y, int prev){
        if(x < 0 || x >= m || y < 0 || y >= n || matrix[x][y] <= prev) return 0;
        if(dp[x][y]) return dp[x][y];
        
        dp[x][y] = max({
            recur(matrix, x+1, y, matrix[x][y]),
            recur(matrix, x-1, y, matrix[x][y]),
            recur(matrix, x, y+1, matrix[x][y]),
            recur(matrix, x, y-1, matrix[x][y]),
        }) + 1;
        
        return dp[x][y];
    }
};
