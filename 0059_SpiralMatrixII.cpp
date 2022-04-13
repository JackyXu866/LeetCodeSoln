class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> rt(n, vector<int>(n, 0));
        
        int layer = 0, num = 1;
        while(n != 0){
            for(int i = layer; i < n; i++, num++) rt[layer][i] = num;
            for(int i = layer+1; i < n; i++, num++) rt[i][n-1] = num;
            for(int i = n-2; i >= layer; i--, num++) rt[n-1][i] = num;
            for(int i = n-2; i >= layer+1; i--, num++) rt[i][layer] = num;
            n--, layer++;
        }
        
        return rt;
    }
};
