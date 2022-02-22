class Solution {
public:
    int titleToNumber(string& columnTitle) {
        int rt = 0;
        for(const auto& c : columnTitle){
            rt *= 26;
            rt += c-64;
        }
        
        return rt;
    }
};
