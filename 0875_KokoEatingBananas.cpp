class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());  
        int count, mid;
        while(low<high){
            mid = (low+high)/2;
            count = 0;
            for(auto i:piles){
                count += i/mid + (i%mid != 0);
            }
            if(count <= h){
                high = mid;
            }
            else{
                low = mid+1;
            }
        }
        
        return high;
    }
};
