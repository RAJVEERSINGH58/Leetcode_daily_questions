#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    int setbit(int n){

        int ans = 0;

        while(n > 0){
            n /= 2;
            ans++;
        }
        return ans;

    }

    int smallestNumber(int n) {

        int count = setbit(n);
        
        return (n == pow(2 , count)) ? pow(2 , count + 1) - 1: pow(2 , count) - 1;

    }
};

int main() {
    
    return 0;
}