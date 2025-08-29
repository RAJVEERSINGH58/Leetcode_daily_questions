#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    long long flowerGame(int n, int m) {

        long long ans = 0;
        
        long long noOfOddInLaneOne , noOfOddInLaneTwo , noOfEvenInLaneOne , noOfEvenInLaneTwo;

        if(n % 2 == 1) noOfOddInLaneOne = n / 2 + 1;
        else noOfOddInLaneOne = n / 2;

        noOfEvenInLaneOne = n - noOfOddInLaneOne;

        if(m % 2 == 1) noOfOddInLaneTwo = m / 2 + 1;
        else noOfOddInLaneTwo = m / 2;

        noOfEvenInLaneTwo = m - noOfOddInLaneTwo;

        ans += (noOfEvenInLaneOne * noOfOddInLaneTwo) + (noOfOddInLaneOne * noOfEvenInLaneTwo);

        return ans;

    }
};

int main() {
    
    return 0;
}