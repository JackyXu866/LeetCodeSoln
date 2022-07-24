class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        if(!m) return false;
        int x = 0, y = matrix[0].size()-1;
        
        // eliminate row by row, column by column
        while(x < m && y >= 0){
            if(matrix[x][y] == target) return true;
            if(matrix[x][y] > target) y--;
            else x++;
        }
        
        return false;
    }
};
