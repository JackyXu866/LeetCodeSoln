class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int len = cardPoints.size() - k;
        int maxS = accumulate(cardPoints.begin(), cardPoints.end(), 0);
        if(len <= 0) return maxS;
        
        int sum = accumulate(cardPoints.begin(), cardPoints.begin()+len-1, 0);
        int rt = INT_MAX;
        for(int i = len-1; i<cardPoints.size(); i++){
            sum += cardPoints[i];
            rt = min(rt, sum);
            sum -= cardPoints[i-len+1];
        }
        
        return maxS - rt;
    }
};
