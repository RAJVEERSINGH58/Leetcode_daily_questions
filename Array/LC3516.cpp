#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int findClosest(int x, int y, int z) {
        
        int len1 = abs(x - z);
        int len2 = abs(y - z);

        if(len1 == len2) return 0;
        else if(len1 > len2) return 2;
        else return 1;

    }
};

int main() {
    
    return 0;
}