class NumMatrix {
public:
    NumMatrix(vector<vector<int>>& matrix) {        
        int m = matrix.size();
        if(m == 0) return;
        int n = matrix[0].size();
        if(n == 0) return;
        
        mt = vector<vector<int>>(m+1, vector<int>(n+1, 0));
        for(int i=1; i<m+1; i++){
            for(int j=1; j<n+1; j++){
                mt[i][j] = mt[i][j-1] + mt[i-1][j] - mt[i-1][j-1] + matrix[i-1][j-1];
            }
        }
    }
    
    int sumRegion(int r1, int c1, int r2, int c2) {
        return mt[r2+1][c2+1] - mt[r1][c2+1] - mt[r2+1][c1] + mt[r1][c1];
    }
    
private:
    vector<vector<int>> mt;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
