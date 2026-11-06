class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int mini = prices[0];
        int maxpro = INT_MIN;

        for(int i = 0 ; i<n ; i++){
            int cost = prices[i] - mini;
            maxpro = max(maxpro , cost);
            mini = min(mini , prices[i]);
        }
        return maxpro;
    }
};