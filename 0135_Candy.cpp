class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size(), rt = 0;
        if(n <= 1) return n;
        vector<int> ppl(n, 1);
        for(int i=1; i<ratings.size(); i++){
            if(ratings[i] > ratings[i-1]) ppl[i] = ppl[i-1]+1;
        }
        
        for(int i=ratings.size()-1; i>=1; i--){
            if(ratings[i-1] > ratings[i]) ppl[i-1] = max(ppl[i-1], ppl[i]+1);
            rt += ppl[i];
        }
        
        return rt+ppl[0];
    }
};
