class Solution {
public:
    int brokenCalc(int startValue, int target) {
        int rt = 0;
        while(startValue < target){
            rt++;
            if(target % 2 == 1) target++;
            else target /= 2;
        }
        
        return rt + startValue - target;
    }
};
