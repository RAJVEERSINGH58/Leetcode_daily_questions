#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();

        int right = 0;
        int left = 0;
        
        int ans = 0;
        int xor_sum = 0;
        int curr_sum = 0;

        while(right < n){
            xor_sum ^= nums[right];
            curr_sum += nums[right];
            while(xor_sum != curr_sum){
                xor_sum ^= nums[left];
                curr_sum -= nums[left];
                left++;
            }
            ans = max(ans , right - left + 1);
            right++;
        }

        return ans;

    }
};

int main() {
    
    return 0;
}
