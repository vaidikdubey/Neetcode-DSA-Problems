class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int minSpeed = 1, maxSpeed = *max_element(piles.begin(), piles.end());

       int requiredSpeed = maxSpeed;

        while(minSpeed <= maxSpeed) {
            int mid = minSpeed + (maxSpeed - minSpeed) / 2;

            long long sum = 0;

            for(int i = 0; i < piles.size(); i++) {
                sum += piles[i]/mid;

                if(piles[i] % mid != 0) {
                    sum++;
                }
            }

            if(sum <= h) {
                requiredSpeed = mid;
                maxSpeed = mid - 1;
            }
            else {
                minSpeed = mid + 1;
            }
        }

        return requiredSpeed;
    }
};
