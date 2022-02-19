class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> tb(60, 0);
        int rt = 0;
        
        for(int i: time){
            int tmp = 60-(i%60);
            if(tmp == 60) tmp = 0; 
            rt += tb[tmp];
            tb[i%60]+=1;
        }
        return rt;
    }
};
