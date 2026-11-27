
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        vector<int> dp(budget + 1, 0);

        int minPrice = INT_MAX;

        for(int i = 0; i < items.size(); i++) {

            int factor = items[i][0];
            int price = items[i][1];

            minPrice = min(minPrice, price);

            int cnt = 0;

            for(int j = 0; j < items.size(); j++) {
                if(items[j][0] % factor == 0) {
                    cnt++;
                }
            }

            // 0/1 Knapsack
            for(int j = budget; j >= price; j--) {
                dp[j] = max(dp[j], dp[j - price] + cnt);
            }
        }

        int ans = 0;

        for(int i = 0; i <= budget; i++) {
            int extra = (budget - i) / minPrice;

            ans = max(ans, dp[i] + extra);
        }

        return ans;
    }
};
