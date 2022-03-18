class Solution {
public:
    string removeDuplicateLetters(string s) {
        int occur[26] = {0};
        int visit[26] = {0};
        
        for(const char& c : s){
            ++occur[c-97];
        }
        
        string rt = "";
        for(const char& c : s){
            occur[c-97]--;
            if(visit[c-97]) continue;
            while(rt != "" && rt.back() > c && occur[rt.back()-97] > 0){
                visit[rt.back()-97] = 0;
                rt.pop_back();
            }
            rt += c;
            visit[c-97] = 1;
        }
        
        return rt;
    }
};
