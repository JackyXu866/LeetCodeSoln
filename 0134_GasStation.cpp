class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total = 0, curr = 0, start = 0;
        for(int i=0; i<gas.size(); i++){
            curr += gas[i] - cost[i];
            if(curr < 0){
                total += curr;
                start = i+1;
                curr = 0;
            }
        }
        total += curr;
        if(total < 0) return -1;
        return start;
    }
};
