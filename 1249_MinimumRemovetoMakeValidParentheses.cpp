class Solution {
public:
    string minRemoveToMakeValid(string& s) {
        int para = 0;
        for(auto i = s.begin(); i != s.end(); ++i){
            if(*i == '(') para++;
            else if(*i == ')'){
                if(para == 0) i = --s.erase(i);
                else --para;
            }
        }
        
        para = 0;
        for(int i=s.size()-1; i >= 0; i--){
            if(s[i] == ')') para++;
            else if(s[i] == '('){
                if(para == 0){
                    s.erase(i, 1);
                }
                else --para;
            }
        }
        
        return s;
    }
};
