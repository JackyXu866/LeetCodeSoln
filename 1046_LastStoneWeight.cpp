class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(int i : stones){
            pq.push(i);
        }
        
        while(pq.size() > 1){
            int a = pq.top();
            pq.pop();
            int b = pq.top();
            pq.pop();
            if(b-a != 0) pq.push(abs(b-a));
        }
        
        return pq.size() != 0 ? pq.top(): 0;
    }
};
