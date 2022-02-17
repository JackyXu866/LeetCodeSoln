class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        if(dict.find(endWord) == dict.end()) return 0;
        queue<string> q;
        q.push(beginWord);
        int rt = 1;
        // dict.erase(beginWord);
        while(!q.empty()){
            int s = q.size();
            rt++;
            for(int i=0; i<s; i++){
                string tmp = q.front();
                q.pop();
                // dict.erase(tmp);
                for(int j=0; j<tmp.size(); j++){
                    string trans = tmp;
                    for(char k = 'a'; k<='z'; k++){
                        trans[j] = k;
                        auto it = dict.find(trans);
                        if(it == dict.end()) continue;
                        if(trans == endWord) return rt;
                        q.push(trans);
                        dict.erase(it);
                    }
                }
            }
        }
        
        return 0;
    }
};
