class Solution {
public:
    bool isValid(string& s) {
        stack<char> para;
        for(const char& c:s){
            switch(c){
                case '(':
                    para.push(')');
                    break;
                case '{':
                    para.push('}');
                    break;
                case '[':
                    para.push(']');
                    break;
                default:
                    if(para.empty()) return false;
                    if(para.top() == c){
                        para.pop();
                    }
                    else return false;
                    break;
            }
        }
        
        if(!para.empty()) return false;
        return true;
    }
};
