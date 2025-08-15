#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPowerOfFour(int n) {
        while(n > 1){
            if(n % 4 != 0) return false;
            n /= 4;
        }
        if(n == 1) return true;
        else return false;
    }
};

int main() {
    
    return 0;
}