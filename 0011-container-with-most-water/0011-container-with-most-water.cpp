class Solution {
public:
    int maxArea(vector<int>& height) {
        unsigned l = 0, r = height.size()-1, maximum = 0, ch = 0, len = 0,area=0;
        while (r > l) {
            ch = min(height[l],height[r]);
            len = r-l;
            area = len*ch;
            maximum= max(area, maximum);
            if(height[r]>height[l]){
                l++;
            }else r--;
        }
        return maximum;
    }
};