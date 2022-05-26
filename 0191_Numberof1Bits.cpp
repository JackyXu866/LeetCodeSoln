class Solution {
public:
    int hammingWeight(uint32_t n) {
        int rt = 0;
        
        while(n){
            rt++;
            n &= n-1;
        }
        
        return rt;
    }
};
