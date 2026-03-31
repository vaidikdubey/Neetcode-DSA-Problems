class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();

        int tower1 = 0, tower2 = n - 1;
        int maxWater = 0;

        while(tower1 < tower2) {
            int water =  (tower2 - tower1) * min(heights[tower1], heights[tower2]);

            maxWater = max(maxWater, water);

            if(heights[tower1] < heights[tower2]) {
                tower1++;
            }
            else {
                tower2--;
            }
        }

        return maxWater;
    }
};
