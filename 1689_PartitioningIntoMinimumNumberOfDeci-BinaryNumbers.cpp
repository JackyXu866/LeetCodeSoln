class Solution {
public:
    int minPartitions(string n) {
        int rt = 0;
        
        for(char c : n){
            rt = max(c-48, rt);
            if(rt == 9) return rt;
        }
        
        return rt;
    }
};
