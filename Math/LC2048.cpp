#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    bool balanced(int n){
        
        string s = to_string(n);

        unordered_map<char , int> mp;

        for(char ch : s) mp[ch]++;

        for(auto x : mp){
            if(x.first - '0' != x.second) return false;
        }

        return true;


    }


    int nextBeautifulNumber(int n) {
        
        for(int i = n + 1 ; i <= 666666 ; i++){

            if(balanced(i)) return i;

        }

        return 1224444;

    }
};

int main() {
    
    return 0;
}