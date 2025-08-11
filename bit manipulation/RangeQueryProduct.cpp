#include<bits/stdc++.h>
#include<vector>

using namespace std;

#define MOD 1000000007
class Solution {
public:

    long long modInverse(long long a) {
        long long result = 1;
        long long base = a;
        long long exp = MOD - 2; 
        
        while (exp > 0) {
            if (exp % 2 == 1) {
                result = (result * base) % MOD;
            }
            base = (base * base) % MOD;
            exp /= 2;
        }
        return result;
    }

    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<long long> powers;
        int m = queries.size();

        int x = 0;

        for(int i = 0 ; i < 32 ; i++){
            if((n & 1) == 1) powers.push_back(pow(2 , x));
            x++;
            n = n>>1;
        }

        for(int i = 1 ; i < powers.size() ; i++){
            powers[i] = (powers[i] * powers[i-1]) % MOD;
        }

        vector<int> ans(m);

        for(int i = 0 ; i < m ; i++){
            int start = queries[i][0];
            int end = queries[i][1];

            if(start != 0){
                ans[i] = (powers[end] * modInverse(powers[start-1])) % MOD;
            }

            else{
                ans[i] = powers[end] % MOD;
            }
        }

        return ans;

    }
};

int main() {
    
    return 0;
}