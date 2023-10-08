class Solution {
public:
    string convert(string s, int numRows) {
        int len = ceil(s.size()/(numRows*1.5 -1)*max(numRows-1, 1));
        vector<vector<char>> rt(numRows, vector<char>(len+1, '_'));

        bool zig = false;
        int x = 0, y = 0;
        for(int i=0; i<s.size(); i++){
            rt[x][y] = s[i];
            if(zig == false){
                x++;
                if(x == numRows-1) zig = true;
                if(x > numRows-1) {
                    y++;
                    x = numRows-1;
                }
            }
            else{
                x--;
                y++;
                if(x == 0) zig = false;
            }
        }

        string ret = "";
        for(int i=0; i<rt.size(); i++){
            for(int j=0; j<rt[0].size(); j++){
                if(rt[i][j] == '_') continue;
                ret += rt[i][j];
            }
        }

        return ret;
    }
};
