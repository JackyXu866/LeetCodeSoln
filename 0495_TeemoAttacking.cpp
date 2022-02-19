class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int tl = 0, rt = 0;
        for(auto i:timeSeries){
            if(tl > i){
                rt += i+duration-tl;
            }
            else rt += duration;
            tl = i+duration;
        }
        return rt;
    }
};
