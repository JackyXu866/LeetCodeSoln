class WordFilter {
public:
    WordFilter(vector<string>& words) {
        for(int i=0; i<words.size(); i++){
            string& w = words[i];
            for(int j=1; j<=w.size(); j++){
                string tmp = w.substr(0, j);
                for(int k=0; k<w.size(); k++){
                    mp[tmp+"#"+w.substr(k)] = i;
                }
            }
            
        }
    }
    
    int f(string p, string s) {
        string tmp = p+"#"+s;
        if(mp.find(tmp) == mp.end()) return -1;
        return mp[tmp];
    }
        
private:
    unordered_map<string, int> mp;
};

/**
 * Your WordFilter object will be instantiated and called as such:
 * WordFilter* obj = new WordFilter(words);
 * int param_1 = obj->f(prefix,suffix);
 */
