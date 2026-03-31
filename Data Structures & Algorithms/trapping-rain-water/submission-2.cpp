class Solution {
public:
    int trap(vector<int>& height) {
        if(height.empty()) return 0;

        int l = 0, r = height.size() - 1;
        int leftMax = height[l], rightMax = height[r];
        int maxWater = 0;

        while(l < r) {
            if(leftMax < rightMax) {
                l++;
                leftMax = max(leftMax, height[l]);
                maxWater += leftMax - height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                maxWater += rightMax - height[r];
            }
        }

        return maxWater;
    }
};
