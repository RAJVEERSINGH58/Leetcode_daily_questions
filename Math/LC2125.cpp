#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int count(string s){

        int ones = 0;

        for(char ch : s) if(ch == '1') ones++;

        return ones;

    }

    int numberOfBeams(vector<string>& bank) {
        
        int ans = 0;
        int n = bank.size();
        int prev = count(bank[0]);

        for(int i = 1 ; i < n ; i++){
            int ones = count(bank[i]);
            if(ones == 0) continue;
            ans += ones * prev;
            prev = ones;
        }

        return ans;

    }
};

int main() {
    
    return 0;
}