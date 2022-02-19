class Solution {
public:
    int minJumps(vector<int>& arr) {
        int rt = 0, n=arr.size();
        if(n <= 1) return 0;
        unordered_map<int, vector<int>> mp;
        
        for(int i=0; i<n; i++){
            mp[arr[i]].push_back(i);
        }
        
        queue<int> q;
        q.push(0);
        
        while(!q.empty()){
            rt++;
            int s = q.size();
            for(int i=0; i<s; i++){
                int j = q.front();
                q.pop();
                if(j-1 >= 0 && mp.find(arr[j-1])!=mp.end()){
                    q.push(j-1);
                }
                if(j+1 < n && mp.find(arr[j+1])!=mp.end()){
                    if(j+1 == n-1) return rt;
                    q.push(j+1);
                }
                if(mp.find(arr[j])!=mp.end()){
                    for(int k:mp[arr[j]]){
                        if(k == j) continue;
                        if(k == n-1) return rt;
                        q.push(k);
                    }
                }
                mp.erase(arr[j]);
            }    
        }
        
        return rt;
    }
};
