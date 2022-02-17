class Solution {
public:
    string addBinary(string& a, string& b) {
        int8_t as = a.length(), bs = b.length(), add = 0;
        int8_t ms = min(as, bs);
        string rt;
        
        for(int8_t i = 0; i<ms; i++){
            int tmp = add + (a[as-i-1]-48) + (b[bs-i-1]-48);
            if(tmp > 1){
                tmp = tmp-2; add = 1;
            }
            else add = 0;
            
            rt = to_string(tmp) + rt;
        }
        
        string rest;
        if(as > ms) rest = a.substr(0, as-ms);
        else rest = b.substr(0, bs-ms);
        
        if(add == 0) rt = rest + rt;
        else if(as == bs) rt = '1' + rt;
        else{
            for(int8_t i=rest.length()-1; i>=0; i--){
                int8_t tmp = add + rest[i]-48;
                if(tmp > 1){
                    tmp = tmp-2; add = 1;
                }
                else add = 0;
                
                rt = to_string(tmp) + rt;
            }
            if(add == 1) rt = '1' + rt;
        }
        
        return rt;
    }
};
