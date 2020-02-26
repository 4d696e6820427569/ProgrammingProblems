class Solution {
    public int maxProfit(int[] prices) {
        int n = prices.length;
        if (n < 2) return 0;
        int[] dp = new int[n];
        dp[0] = 0;
        dp[1] = prices[0] < prices[1] ? prices[1] - prices[0] : 0;


        for (int i = 2; i < n; i++) {
            dp[i] = dp[i-1];
            for (int j = 0; j < i; j++) {
                dp[i] = Math.max(dp[i], prices[i] - prices[j]);
            }
        }

        return dp[n-1];

    }


}
