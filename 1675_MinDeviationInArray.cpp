class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int> pq;
        int minv = INT_MAX;
        int rt = INT_MAX;
        // multiply all odds + find min
        for(int& i : nums){
            if(i%2 == 1) i *= 2;
            pq.push(i);
            minv = min(minv, i);
        }
        
        while(pq.top()%2 == 0){
            int tmp = pq.top();
            pq.pop();
            rt = min(rt, tmp-minv);
            minv = min(tmp/2, minv);
            pq.push(tmp/2);
        }
        
        return min(rt, pq.top()-minv);
    }
};
