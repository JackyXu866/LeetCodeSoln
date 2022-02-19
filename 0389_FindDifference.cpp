class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> cs;
        for(auto c:s){
            cs[c]++;
        }
        
        for(auto c:t){
            if(cs.find(c) == cs.end()){
                return c;
            }
            cs[c]--;
            if(cs[c]<0) return c;
        }
        return ' ';
    }
};
