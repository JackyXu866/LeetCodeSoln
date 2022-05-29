class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> mask(words.size());
        int rt = 0;
        
        for(int i=0; i<words.size(); i++){
            int tmp = 0;
            for(const char& c : words[i]){
                mask[i] |= 1 << (c-'a');
            }
            
            for(int j=0; j<i; j++){
                // no common
                if((mask[j] & mask[i]) == 0){
                    rt = max(rt, (int)(words[j].size()*words[i].size()));
                }
            }
        }
        
        return rt;
    }
};
