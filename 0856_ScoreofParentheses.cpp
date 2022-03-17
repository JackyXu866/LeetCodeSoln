class Solution {
public:
    int scoreOfParentheses(string s) {
        stack<int> st;
        st.push(0);
        
        for(const char& c : s){
            if(c == '(') st.push(0);
            else{
                int tmp1 = st.top();
                st.pop();
                int tmp2 = st.top();
                st.pop();
                st.push(tmp2 + max(2*tmp1, 1));
            }
        }
        
        return st.top();
    }
};
