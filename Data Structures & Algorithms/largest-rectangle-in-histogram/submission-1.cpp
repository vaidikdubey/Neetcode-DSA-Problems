class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int left = i, right = i;

            //Left loop
            for(int j = i - 1; j >= 0; j--) {
                if(heights[j] < heights[i]) break;
                
                left = j;
            }
            //Right loop
            for(int j = i + 1; j < n; j++) {
                if(heights[j] < heights[i]) break;
                
                right = j;
            }

            int area = heights[i] * (right - left + 1);

            maxArea = max(area, maxArea);
        }

        return maxArea;
    }
};
