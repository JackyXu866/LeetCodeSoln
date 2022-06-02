class Solution {
public:
    int romanToInt(string s) {
        int prev = 0, rt = 0;
        for(int i=s.size()-1; i>=0; i--){
            int curr;
            switch(s[i]){
                case 'I':
                    curr = 1;
                    break;
                case 'V':
                    curr = 5;
                    break;
                case 'X':
                    curr = 10;
                    break;
                case 'L':
                    curr = 50;
                    break;
                case 'C':
                    curr = 100;
                    break;
                case 'D':
                    curr = 500;
                    break;
                case 'M':
                    curr = 1000;
                    break;
                default:
                    break;
            }
            if(curr < prev) rt -= curr;
            else rt += curr;
            prev = curr;
        }
        
        return rt;
    }
};
