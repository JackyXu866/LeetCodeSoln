class Solution {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size()-1, rt = min(height[l], height[r])*(r-l);
        
        while(l < r) {
            if(height[l] < height[r]) ++l;
            else --r;
            
            rt = max(rt, min(height[l], height[r])*(r-l));
        }
        
        return rt;
    }
};
