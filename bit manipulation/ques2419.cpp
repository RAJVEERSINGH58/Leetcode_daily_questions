#include<bits/stdc++.h>
#include<vector>
using namespace std;class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        int ans = 1;
        int prev = 0;

        int maxval = *max_element(nums.begin() , nums.end());

        for(int i = 0 ; i < n ; i++){
            if(nums[i] == maxval) prev++;
            else{
                ans = max(ans , prev);
                prev = 0;
            }
        }

        ans = max(ans , prev);

        
        return ans;

    }
};