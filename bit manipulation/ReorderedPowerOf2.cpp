#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool reorderedPowerOf2(int n) {
        int x = 1;
        string s = to_string(n);
        sort(s.begin() , s.end());

        for(int i = 0 ; i < 32 ; i++){
            string t = to_string(1<<i);
            sort(t.begin() , t.end());

            if(s == t) return true;

        }

        return false;

    }
};

int main() {
    
    return 0;
}