class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        vector<int> start;
        vector<int> end;
        vector<int> rt;

        for(vector<int>& a: flowers){
            start.push_back(a[0]);
            end.push_back(a[1]+1);
        }

        sort(start.begin(), start.end());
        sort(end.begin(), end.end());

        for(int ppl: people){
            int i = upper_bound(start.begin(), start.end(), ppl) - start.begin();
            int j = upper_bound(end.begin(), end.end(), ppl) - end.begin();
            rt.push_back(i-j);
        }

        return rt;
    }
};
