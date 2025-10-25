#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int totalMoney(int n) {

        int ans = 0;

        int week = n / 7;
        int days = n % 7;

        ans = (week * 28) + 7 * (week * (week - 1)) / 2;

        week++;

        while(days > 0){
            ans += week++;
            days--;
        }

        return ans;

    }
};

int main() {
    
    return 0;
}