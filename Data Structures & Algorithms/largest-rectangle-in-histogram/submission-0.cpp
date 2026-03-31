class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int maxArea = 0;

        for(int i = 0; i < n; i++) {
            int left = i, right = i;

            //Left loop
            for(int j = 0; j < i; j++) {
                if(heights[j] >= heights[i])
                    left = j;
            }
            //Right loop
            for(int j = i + 1; j < n; j++) {
                if(heights[j] >= heights[i])
                    right = j;
            }
            
            //Exclude the min bars found on both sides
            left++;
            right--;

            cout << "Left " << left <<  endl;
            cout << "Right " << right << endl; 

            int area = heights[i] * (right - left + 1);

            cout << "Area " << area << endl;

            maxArea = max(abs(area), maxArea);
        }

        return maxArea;
    }
};
