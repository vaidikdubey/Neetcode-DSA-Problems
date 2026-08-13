class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea = 0;

        int i = 0, j = heights.size() - 1;

        while(i < j) { //O(n)
            int area = (j - i) * min(heights[i], heights[j]);

            maxArea = max(maxArea, area);

            if(heights[i] < heights[j]) i++;
            else j--;
        }

        return maxArea; //T.C: O(n), S.C: O(1)
    }
};
