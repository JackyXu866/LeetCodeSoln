/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

int findpeak(MountainArray &arr, int i){
    // 0 - left, 1 - peak, 2 - right
    if(i == 0) return 0;
    if(i == arr.length()-1) return 2;

    int li = arr.get(i-1);
    int ri = arr.get(i+1);
    int ii = arr.get(i);

    if(li < ii && ii < ri) return 0;
    else if(li < ii && ii > ri) return 1;
    else return 2;
}
int get(MountainArray &arr, int i){
    return arr.get(i);
}

class Solution {
public:


    int binarysearch(MountainArray &arr, int l, int r, int target, int (*func)(MountainArray&, int)){
        int mid, res;
        while(l<=r){
            mid = l + (r-l)/2;
            res = func(arr, mid);
            if(res == target) return mid;
            if(res < target) l = mid+1;
            else r = mid-1;
        }
        return INT_MAX;
    }

    int binarysearchrev(MountainArray &arr, int l, int r, int target, int (*func)(MountainArray&, int)){
        int mid, res;
        while(l<=r){
            mid = l + (r-l)/2;
            res = func(arr, mid);
            if(res == target) return mid;
            if(res < target) r = mid-1;
            else l = mid+1;
        }
        return INT_MAX;
    } 

    int findInMountainArray(int target, MountainArray &arr) {
        int l = 0, r = arr.length()-1;

        int peak = binarysearch(arr, l, r, 1, &findpeak);
        cout << "peak " << peak << endl;
        int res = min(binarysearch(arr, l, peak, target, &get), binarysearchrev(arr, peak, r, target, &get));
        if(res > r) return -1;

        return res;    
    }
};
