class Solution {
public:
    int divide(long dividend, long divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        
        uint a = abs(dividend), b = abs(divisor), rt = 0;
        
        for(int i = 31; i>=0; i--){
            if((a>>i) >= b){
                a -= b<<i;
                rt += (1<<i);
            }
        }
        
        return (dividend < 0) == (divisor < 0) ? rt : -rt;
    }
};
