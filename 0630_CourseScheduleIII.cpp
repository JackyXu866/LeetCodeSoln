class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int curr = 0;
        priority_queue<int> pq;
        
        sort(courses.begin(), courses.end(), [](const vector<int>& a, const vector<int>& b){
            return a[1] < b[1];
        });
        
        for(auto & i : courses){
            curr += i[0];
            pq.push(i[0]);
            if(curr > i[1]){
                curr -= pq.top();
                pq.pop();
            }
        }
        return pq.size();
    }
    
};
