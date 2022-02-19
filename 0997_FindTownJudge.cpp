class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        map<int, int> tr;
        for(int i=1; i<=n; i++){
            tr[i] = 0;
        }
        
        
        for(vector<int> i : trust){
            tr.erase(i[0]);
            if(tr.find(i[1])!=tr.end()) tr[i[1]]++;
        }
        
        if(tr.size()!=1) return -1;
        
        if(tr.begin()->second == n-1) return tr.begin()->first;
        
        return -1;
    }
};
