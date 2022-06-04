class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> rt;
        vector<string> pos(n, string(n, '.'));
        int q[n];
        soln(rt, pos, q, 0, n);
        return rt;
    }
    
private:
    void soln(vector<vector<string>>& rt, vector<string>& pos, int* q, int r, int n){
        if(r == n){
            rt.push_back(pos);
            return;
        }
        
        for(int c=0; c<n; c++){
            if(valid(q, r, c)){
                *(q+r) = c;
                pos[r][c] = 'Q';
                soln(rt, pos, q, r+1, n);
                pos[r][c] = '.';
                *(q+r) = -1;
            }
        }
    }
    
    bool valid(int* q, int r, int c){
        for(int i=0; i<r; i++){
            if(*(q+i) == c || abs(r-i) == abs(*(q+i)-c)) return false;
        }
        return true;
    }
};
