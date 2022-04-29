class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        visited.resize(s.size());
        graph.resize(s.size());
        
        for(auto& p : pairs){
            int i = p[0], j = p[1];
            graph[i].push_back(j);
            graph[j].push_back(i);
        }
        
        for(int i=0; i<s.size(); ++i){
            if(!visited[i]){
                vector<char> chara;
                vector<int> index;
                
                DFS(index, chara, s, i);
                
                sort(index.begin(), index.end());
                sort(chara.begin(), chara.end());
                
                for(int j=0; j<chara.size(); j++){
                    s[index[j]] = chara[j];
                }
            }
        }
        
        return s;
    }
    
private:
    vector<vector<int>> graph;
    vector<bool> visited;
    
    void DFS(vector<int>& index, vector<char>& chara, string_view s, int i){
        chara.push_back(s[i]);
        index.push_back(i);
        
        visited[i] = true;
        
        for(int nxt : graph[i]){
            if(!visited[nxt]) DFS(index, chara, s, nxt);
        }
    }
};
