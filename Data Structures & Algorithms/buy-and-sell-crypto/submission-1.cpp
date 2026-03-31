class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int buy = 0, sell = 1;
        int profit = 0;

        while(sell < prices.size()) {
            if(prices[sell] > prices[buy]) {
                int currProfit = prices[sell] - prices[buy];

                profit = max(profit, currProfit);
            }
            else {
                buy = sell;
            }
            sell++;
        }

        return profit;
    }
};
