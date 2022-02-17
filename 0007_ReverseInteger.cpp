#include <string>

class Solution {
public:
    int reverse(int x) {
        int rt = 0;
        while(x != 0){
            if(abs(rt) > INT_MAX/10) return 0;
            rt = rt*10 + x%10;
            x /= 10;
        }
        return rt;
    }
};
