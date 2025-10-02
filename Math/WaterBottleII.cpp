#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int maxBottlesDrunk(int numBottles, int numExchange) {
        
        int ans = numBottles;
        int emptyBottle = numBottles;
        numBottles = 0;

        while(numBottles > 0 || emptyBottle >= numExchange){

            while(emptyBottle >= numExchange){
                emptyBottle -= numExchange;
                numExchange++;
                numBottles++;
            }

            ans += numBottles;
            emptyBottle += numBottles;
            numBottles = 0;

        }

        return ans;

    }
};

class Solution {
public:

    unordered_map<long long , int> dp;

    int solve(int bot , int exc , int empt){
        if(bot == 0 && empt < exc) return 0;

        long long key = ((long long)bot << 30) | ((long long)bot << 15) | empt;
        if(dp.count(key) > 0) return dp[key];

        int d = INT_MIN , e = INT_MIN;
        if(bot > 0) d = bot +  solve(0 , exc , empt + bot);
        if(empt >= exc) e = solve(bot + 1 , exc + 1 , empt - exc);

        return dp[key] =  max(d , e);

    }

    int maxBottlesDrunk(int numBottles, int numExchange) {
        return solve(numBottles, numExchange , 0);
    }
};

int main() {
    
    return 0;
}