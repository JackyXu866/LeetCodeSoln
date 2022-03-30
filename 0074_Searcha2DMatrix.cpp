class Solution {
public:
    bool searchMatrix(const vector<vector<int>>& matrix, int target){
        int l = 0, r = matrix.size()-1, n = matrix[0].size()-1, mid, midd;
        while(l <= r){
            mid = l + (r-l)/2;
            if(target >= matrix[mid][0] && target <= matrix[mid][n]) break;
            else if(target < matrix[mid][n]) r = mid-1;
            else l = mid+1;
            cout << mid << endl;
        }
        
        l = 0; r = matrix[mid].size()-1;
        while(l <= r){
            midd = l + (r-l)/2;
            if(matrix[mid][midd] == target) return true;
            else if(matrix[mid][midd] > target) r = midd-1;
            else l = midd+1;
        }
        
        return false;
    }
};
