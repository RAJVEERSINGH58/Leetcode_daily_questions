#include<bits/stdc++.h>
#include<vector>

using namespace std;

#define mod 1000000007
class Solution {
public:

    long long dp[305][305];

    int f(vector<long long>& powers , int idx , int target){
        if(target == 0) return 1;
        if(target < 0 || idx >= powers.size()) return 0;

        if(dp[idx][target] != -1) return dp[idx][target];

        long long x = 0;

        if(target -  powers[idx] >= 0) x += f(powers , idx + 1 , target -  powers[idx]) % mod;

        x = (x % mod + (f(powers , idx + 1 , target) % mod)) % mod;

        return dp[idx][target] = x;

    }

    long long logPow(int x , int n){//x^n
        if(n == 1) return x;

        long long ans = logPow(x , n / 2);

        if(n % 2 == 0) return ans * ans;
        else return ans * ans * x;

    }

    int numberOfWays(int n, int x) {
        
        vector<long long> powers;

        for(int i = 1 ; i <= n ; i++){
            powers.push_back(logPow(i , x));
        }

        memset(dp , -1 , sizeof dp);

        return f(powers , 0 , n) % mod;

    }
};

int main() {
    
    return 0;
}