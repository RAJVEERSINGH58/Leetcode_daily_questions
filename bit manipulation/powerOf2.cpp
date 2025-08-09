#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        return !(n & n - 1);

    }
};

class Solution {
public:
    bool isPowerOfTwo(int n) {
        if (n <= 0) return false;
        
        int cnt = 0;
        for(int i = 0 ; i < 31 ; i++){
            if((n & 1) == 1) cnt++;
            n = n>>1;
        }

        if(cnt == 1) return true;
        return false;

    }
};

int main() {
    
    return 0;
}