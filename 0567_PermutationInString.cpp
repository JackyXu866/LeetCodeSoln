class Solution {
public:
    bool checkInclusion(string& s1, string& s2) {
        if(s2.size() < s1.size()) return false;
        
        vector<int> s1c(26);
        bool allz = true;
        for(auto c:s1) ++s1c[c-'a'];
        int s = s1.size();
        for(int i=0; i<s2.size()-s+1; i++){
            string tmp = s2.substr(i, s);
            for(auto c:tmp) --s1c[c-'a'];
            for(auto i:s1c){
                if(i != 0){
                    allz = false;
                    break;
                }
            }
            if(allz) return true;
            allz = true;
            for(auto c:tmp) ++s1c[c-'a'];
        }
        
        return false;
    }
};
