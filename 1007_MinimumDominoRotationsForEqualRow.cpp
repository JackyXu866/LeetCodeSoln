class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int num[7] = {0};
        for(int i=0; i<tops.size(); i++){
            ++num[tops[i]];
            if(tops[i] != bottoms[i]) ++num[bottoms[i]];
        }
        
        int rot = INT_MAX;
        for(int i=1; i<7; i++){
            if(num[i] >= tops.size()){
                int tmp = 0;
                for(int j : tops){
                    if(j != i) ++tmp;
                }
                rot = min(tmp, rot);
                tmp = 0;
                for(int j : bottoms){
                    if(j != i) ++tmp;
                }
                rot = min(tmp, rot);
            }
        }
        if(rot == INT_MAX) return -1;
        return rot;
    }
};
