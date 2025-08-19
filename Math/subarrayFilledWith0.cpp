#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    long long zeroFilledSubarray(vector<int>& nums) {
        
        long long ans = 0;

        int n = nums.size();

        long long curr = 0;

        // subarrays from k consecutive zeros is (k * k + 1) / 2

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == 0) curr++;
            else{
                ans += (curr * (curr + 1)/2);
                curr = 0;
            }
        }

        ans += (curr * (curr + 1)) / 2;

        return ans;

    }
};

int main() {
    
    return 0;
}