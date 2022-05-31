class Solution {
public:
    bool hasAllCodes(string& s, int k) {
        vector<bool> check(1<<k, false);
        int rt = 0, mask = check.size()-1, tmp = 0;
        
        for(int i=0; i<s.size(); i++){
            // mask for limit length
            tmp = mask & ((tmp<<1) + s[i] - '0');
            // check after reach length
            if(i >= k-1 && !check[tmp]){
                check[tmp] = true;
                rt++;
            }
        }

        return rt == check.size();
    }
};
