class Solution {
public:
    int countOrders(int n) {
        int mod = 1e9+7;
        long rt = 1;
        
        for(int i=1; i<=n; i++) {
            rt *= (2*i-1)*i;
            rt = rt%mod;
        }
        
        return (int)rt;
    }
};
