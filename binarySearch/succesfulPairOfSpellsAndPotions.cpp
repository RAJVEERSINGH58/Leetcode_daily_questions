#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        
        int n = spells.size();
        int m = potions.size();

        sort(potions.begin() , potions.end());

        vector<int> ans(n);

        for(int i = 0 ; i < n ; i++){

            long long need = (success + spells[i] - 1) / spells[i];
            auto it = lower_bound(potions.begin(), potions.end(), need);
            ans[i] = m - (it - potions.begin());

        }

        return ans;

    }
};

int main() {
    
    return 0;
}