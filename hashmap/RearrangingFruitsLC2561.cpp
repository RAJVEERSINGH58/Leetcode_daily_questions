#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {

        int n = basket1.size();

        map<int , int> mp;

        int minval = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            mp[basket1[i]]++;
            mp[basket2[i]]--;
            minval = min({minval , basket1[i] , basket2[i]});
        }

        vector<int> v;

        for(pair<int , int> x : mp){
            int freq = x.second;
            if(freq % 2 != 0) return -1;
            for(int i = 0; i < abs(freq) / 2; ++i){
                v.push_back(x.first);
            }
        }

        long long ans = 0;

        for(int i = 0 ; i < v.size() / 2 ; i++){
            ans += min({2 * minval , v[i]});
        }

        return ans;

    }
};

int main() {
    
    return 0;
}