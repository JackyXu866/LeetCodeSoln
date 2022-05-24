class Solution {
public:
    int longestValidParentheses(string s) {
        int rt = 0, balance = 0, clen = 0;
        
        for(auto c : s){
            if(c == '(') balance++;
            if(c == ')') balance--;
            
            if(balance == 0) {
                clen++;
                rt = max(clen, rt);
            }
            else if(balance < 0){
                clen = 0, balance = 0;
            }
            else{
                clen++;
            }
        }
        
        balance = 0, clen = 0;
        for(int i = s.size()-1; i>=0; i--){
            if(s[i] == '(') balance--;
            if(s[i] == ')') balance++;
            
            if(balance == 0) {
                clen++;
                rt = max(clen, rt);
            }
            else if(balance < 0){
                clen = 0, balance = 0;
            }
            else{
                clen++;
            }
        }
        
        return rt;
    }
};
