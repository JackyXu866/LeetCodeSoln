class Solution {
public:
    int expressiveWords(string s, vector<string>& words) {
        int rt = 0;
        for(auto i : words){
            int j = 0, k = 0;
            bool add = true;
            while(j < s.size() && k < i.size()){
                int ns = 0, ni = 0;
                char cs = s[j], ci = i[k];
                if(cs != ci) {add = false; break;}
                
                while(cs == s[j]){
                    ns++;
                    j++;
                }
                while(ci == i[k]){
                    ni++;
                    k++;
                }
                
                if(!((ni < ns && ns >= 3) || ns == ni)) {
                    add = false; break;
                }
            }
            if(j != s.size() || k !=i.size()) add = false;
            if(add) rt++;
        }
        
        return rt;
    }
};
