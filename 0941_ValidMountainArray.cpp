class Solution {
public:
    bool validMountainArray(vector<int>& arr) {
        if(arr.size() <  3) return false;
        if(arr[1] <= arr[0]) return false;
        bool climb = true;
        for(int i=2; i<arr.size(); i++){
            if(climb && i == arr.size()-1 && arr[i-1] <= arr[i]) return false;
            else if(climb && arr[i-1] > arr[i]) climb = false;
            else if(climb && arr[i-1] == arr[i]) return false;
            else if(!climb && arr[i-1] <= arr[i]) return false;
        }
        return true;
    }
};
