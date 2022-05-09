class Solution {
public:
    vector<string> letterCombinations(string& digits) {
        recur(digits);
        return rt;
    }
    
private:
    vector<string> mp = {
        "", "", "abc", "def", "ghi", "jkl",
        "mno", "pqrs", "tuv", "wxyz"
    };
    vector<string> rt;
    
    void recur(string& digit, int n=0, string res=""){
        if(n>=digit.size()){
            if(res != "") rt.push_back(res);
            return;
        }
        
        for(auto c : mp[(digit[n]-48)]){
            recur(digit, n+1, res+c);
        }
    }
};
