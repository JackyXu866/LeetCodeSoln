class Solution {
public:
    string removeKdigits(string num, int k) {
        int i = 0;
        if(k >= num.size()) return "0";
        while(k > 0 && i+1<num.size()){
            if(num[i+1] < num[i]){
                num.erase(i, 1);
                --i;
                if(i < 0) i = 0;
                k--;
            }
            else{
                i++;
            }
        }
        num = num.substr(0, num.size()-k);
        num.erase(0, num.find_first_not_of('0'));
        if(num == "") num = "0";
        return num;
    }
};
