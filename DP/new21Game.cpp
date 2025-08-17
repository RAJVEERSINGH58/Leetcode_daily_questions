#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k == 0 || n >= k + maxPts)
            return 1.0;

        vector<double> dp(n + 1, 0.0);

        // Base case: scores from k to n are winning, with probability 1
        for (int i = k; i <= n; i++) {
            dp[i] = 1.0;
        }

        // Initialize sliding window sum over dp[k] to dp[k + maxPts - 1]
        double windowSum = 0.0;
        for (int i = k; i < k + maxPts && i <= n; i++) {
            windowSum += dp[i];
        }

        // Fill dp[i] backwards for i from k-1 downto 0 using windowSum
        for (int i = k - 1; i >= 0; i--) {

            // dp[i] =
            //     (1 / maxPts) × dp[i + 1] + (1 / maxPts) × dp[i + 2] + ... +
            //     (1 / maxPts) × dp[i + maxPts]

            //     dp[i] =
            //         (1 /
            //          maxPts) × [dp[i + 1] + dp[i + 2] + ... + dp[i + maxPts]]

            //     dp[i] = (1 / maxPts) × windowSum

            dp[i] = windowSum / maxPts;

            // Slide the window left: Remove dp[i + maxPts], add dp[i]
            if (i + maxPts <= n) {
                windowSum -= dp[i + maxPts];
            }
            windowSum += dp[i];
        }

        return dp[0];
    }
};


int main() {
    
    return 0;
}