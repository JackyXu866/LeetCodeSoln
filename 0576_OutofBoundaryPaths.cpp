class Solution {
public:
    int findPaths(int _m, int _n, int maxMove, int startRow, int startColumn) {
        m = _m, n = _n;
        memset(dp, -1, sizeof(dp));
        return recur(maxMove, startRow, startColumn);
    }
private:
    int dp[50][50][51];
    int m, n;
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int mod = 1000000007;
    
    int recur(int move, int r, int c){
        if(r < 0 || r >= m || c < 0 || c >= n) return 1;
        if(!move) return 0;
        if(dp[r][c][move] != -1) return dp[r][c][move];
        
        int rt = 0;
        for(auto i : dir){
            rt = (recur(move-1, r+i[0], c+i[1]) + rt) % mod;
        }
        dp[r][c][move] = rt;
        return rt;
    }
};
