class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> index;
        int area = 0, h, w;
        index.push(0);
        heights.push_back(0);
        
        for(int i=1; i<heights.size(); i++){
            while(!index.empty() && heights[index.top()] > heights[i]){
                h = heights[index.top()];
                index.pop();
                if(index.empty()) w = i;
                else w = i - index.top() - 1;
                area = max(area, w*h);
            }
            index.push(i);
        }
        
        return area;
    }
};
