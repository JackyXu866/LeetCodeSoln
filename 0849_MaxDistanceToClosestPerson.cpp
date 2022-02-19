class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int beg = 0;
        int maxDist = 0;
        int s = seats.size();
        bool track = false;
        
        for(int i=0; i<s; i++){
            if(seats[i] == 1){
                if(!track) continue;
                track = false;
                int tmp;
                if(beg == 0) tmp = i-beg;
                else tmp = (i-beg+1)/2;
                if(maxDist <= tmp){
                    maxDist = tmp;
                }
                continue;
            }
            
            if(!track){
                beg = i;
                track = true;
            }
        }
        if(track){
            maxDist = max(maxDist, s-beg);
        }
        
        return maxDist;
    }
};
