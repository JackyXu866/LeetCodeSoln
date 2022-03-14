class Solution {
public:
    string simplifyPath(string path) {
        string tmp = "";
        stack<string> p;
        for(const char& c : path){
            if(c != '/') tmp += c;
            else{
                if(tmp == ".." && !p.empty()) p.pop();
                else if(tmp == ".." && p.empty()) ;
                else if(tmp == "") ;
                else if(tmp != ".") p.push(tmp);
                tmp = "";
            }
        }
        if(tmp == ".." && !p.empty()) p.pop();
        else if(tmp != "" && tmp != ".." && tmp != ".") p.push(tmp);
        
        if(p.empty()) return "/";
        string rt = "";
        while(!p.empty()){
            rt = "/" + p.top() + rt;
            p.pop();
        }
        return rt;
    }
};
