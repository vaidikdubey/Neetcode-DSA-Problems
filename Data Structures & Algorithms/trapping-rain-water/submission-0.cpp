class Solution {
public:
    int trap(vector<int>& height) {
       if(height.empty()) return 0;

        int n = height.size();
        int maxWater = 0;

        for(int i = 0; i < n; i++) {
            int left = height[i];
            int right = height[i];

            for(int j = 0; j < i; j++) {
                left = max(left, height[j]);
            }
            for(int j = i+1; j < n; j++) {
                right = max(right, height[j]);
            }

            maxWater += min(left, right) - height[i];
        }

        return maxWater;
    }
};
