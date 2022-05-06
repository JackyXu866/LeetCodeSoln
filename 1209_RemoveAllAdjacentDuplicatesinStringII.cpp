class Solution {
public:
    string removeDuplicates(string& s, int k) {
        stack<pair<char, int>> st;
        
        for(auto c : s){
            if(st.empty() || st.top().first != c) st.push({c, 1});
            else{
                st.top().second++;
                if(st.top().second == k) st.pop();
            }
        }
        
        string rt = "";
        while(!st.empty()){
            rt.append(st.top().second, st.top().first);
            st.pop();
        }
        reverse(rt.begin(), rt.end());
        return rt;
    }
};
