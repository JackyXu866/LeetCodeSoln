class Solution {
public:
    int maxArea(int h, int w, vector<int>& hc, vector<int>& vc) {
        return ((long)maxDiff(hc, h) * maxDiff(vc, w))%(1000000007);
    }
    
private:
    int maxDiff(vector<int>& v, int l){
        sort(v.begin(), v.end());
        int rt = max(v[0], l - v[v.size()-1]);
        for(int i=0; i<v.size()-1; i++){
            rt = max(rt, v[i+1]-v[i]);
        }
        
        return rt;
    }
};
