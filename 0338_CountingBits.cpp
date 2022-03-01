class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> rt(n+1, 0);
        rt[0] = 0;
        
        int exp2 = 1;
        for(int i = 1; i<n+1; i++){
            if(i == exp2*2){
                exp2 *= 2;
            }
            rt[i] = rt[i-exp2]+1;
        }
        
        return rt;
    }
};
