class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> st;
        vector<int> rt;
        
        for(int i=0; i<mat.size(); i++){
            int count = 0;
            for(int j : mat[i]){
                if(j == 0) break;
                ++count;
            }
            st.push_back(make_pair(count, i));
        }
        sort(st.begin(), st.end());
        for(int i=0; i<k; i++){
            rt.push_back(st[i].second);
        }
            
        return rt;
    }
};
