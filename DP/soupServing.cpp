#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    float f(int a , int b , vector<vector<int>> & v , vector<vector<float>>& dp){

        if(a == 0 && b == 0) return dp[a][b] = 0.5;
        if(a == 0) return dp[a][b] = 1;
        if(b == 0) return dp[a][b] = 0;

        if(dp[a][b] > -0.9) return dp[a][b];

        float ans = 0.0f;

        for(int i = 0 ; i < 4 ; i++){
            int x = max(0, a - v[i][0]);
            int y = max(0, b - v[i][1]);

            ans += 0.25 * f(x , y , v , dp);
        }

        return dp[a][b] = ans;

    }

    double soupServings(int n) {

        if (n > 5000) return 1.0; 

        n = (n + 24) / 25;

        vector<vector<int>> v = {{4 , 0} , {3 , 1} , {2 , 2} , {1 , 3}};

        vector<vector<float>> dp(n + 5 , vector<float>(n + 5 , -1.0f));

        float ans = f(n , n, v , dp);

        return std::round(ans * 1e5f) / 1e5f;
        
    }
};

int main() {
    
    return 0;
}