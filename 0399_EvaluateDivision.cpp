class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double> rt;
        
        for(int i=0; i<equations.size(); i++){
            unionval(equations[i][0], equations[i][1], values[i]);
        }
        
        for(int i=0; i<queries.size(); i++){
            string& tmp1 = queries[i][0], &tmp2 = queries[i][1];
            if(parent.find(tmp1) != parent.end() && parent.find(tmp2) != parent.end() && find(tmp1) == find(tmp2))
                rt.push_back(val[tmp1]/val[tmp2]);
            else rt.push_back(-1.0);
        }
        
        return rt;
    }
    
private:
    unordered_map<string, string> parent;   // var: root
    unordered_map<string, double> val;         // var: var/root
    
    string find(string& var){
        if(parent.find(var) == parent.end()) return var;
        string& tmp = parent[var];
        if(tmp != var){
            string partmp = find(tmp);
            val[var] = val[var]*val[tmp];
            parent[var] = partmp;
        }
        
        return parent[var];
    }
    
    void add(string& var){
        if(parent.find(var) != parent.end()) return;
        parent[var] = var;
        val[var] = 1.0;
    }
    
    void unionval(string& a, string& b, double _val){
        add(a);
        add(b);
        string pa = find(a), pb = find(b);
        parent[pa] = pb;
        val[pa] = _val*val[b]/val[a];
    }
};
