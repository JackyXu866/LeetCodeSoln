class Solution {
public:
    string longestPalindrome(string& s) {
        if(s == "") return "";
        int r_b = 0, r_s = 1;
        
        for(int i=0; i<s.size(); i++){
            expandPali(i, i, s, r_b, r_s);
            expandPali(i, i+1, s, r_b, r_s);
        }
        
        return s.substr(r_b, r_s);
    }
    
private:
    void expandPali(int b, int e, string& s, int& r_b, int& r_s){
        while(b>=0 && e<s.size() && s[b] == s[e]){
            if(r_s < e-b+1){
                r_b = b;
                r_s = e-b+1;
            }
            b--, e++;
        }
    }
};
