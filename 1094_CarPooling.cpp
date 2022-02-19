class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int trav[1001] = {0};
        int pass = 0;
        for(auto i:trips){
            trav[i[1]] += i[0];
            trav[i[2]] -= i[0];
        }
        for(auto i:trav){
            pass += i;
            if(pass > capacity) return false;
        }
        
        return true;
    }
};
