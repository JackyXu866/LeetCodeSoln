class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), [](const vector<int>& a, const vector<int>& b){
           return a[1] > b[1]; 
        });
        
        int rt = 0;
        for(vector<int>& i : boxTypes){
            rt += min(i[0], truckSize) * i[1];
            truckSize -= i[0];
            if(truckSize <= 0) return rt;
        }
        
        return rt;
    }
};
