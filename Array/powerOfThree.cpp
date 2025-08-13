#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool isPowerOfThree(int x) {

        while(x >= 3){  
            if(x % 3 != 0) return false;
            x /= 3;
        }

        if(x == 1) return true;
        else return false;

    }
};

int main() {
    
    return 0;
}