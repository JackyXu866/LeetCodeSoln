class Solution {
public:
    string convertToTitle(int columnNumber) {
        string rt = "";
        while(columnNumber > 0){
            int tmp = columnNumber % 26;
            if(tmp == 0) tmp = 26;
            columnNumber = (columnNumber - tmp)/26;
            rt = (char)(tmp + 64) + rt;
        }
        return rt;
    }
};
