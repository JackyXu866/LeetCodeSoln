class Solution {
public:
    vector<int> sequentialDigits(int low, int high) {
        string num = "123456789";
        int lowL = to_string(low).length();
        int highL = to_string(high).length();
        vector<int> rt;
        for(int i=lowL; i<=highL; i++){
            for(int j=0; j<=9-i; j++){
                int tmp = stoi(num.substr(j, i));
                if(tmp >= low && tmp <= high){
                    rt.push_back(tmp);
                }
            }
        }
        return rt;
    }
    
};
