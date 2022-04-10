class Solution {
public:
    int calPoints(vector<string>& ops) {
        vector<int> res;
        for(const string& i : ops){
            if(i == "+")
                res.push_back(res[res.size()-1] + res[res.size()-2]);
            else if(i == "D") res.push_back(res.back()*2);
            else if(i == "C") res.pop_back();
            else res.push_back(stoi(i));
        }
        
        int sum = 0;
        for(const int& i : res) sum += i;
        
        return sum;
    }
};
