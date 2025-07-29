#include<bits/stdc++.h>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> smallestSubarrays(vector<int>& nums) {
        int n = nums.size();

        int maxval = *max_element(nums.begin() , nums.end());
        int bit = (maxval == 0) ? 0 : 1 + log2(maxval);

        vector<int> nearest_setbit(bit , n);
        vector<int> ans(n);

        for(int i = n - 1 ; i >= 0 ; i--){
            int nearest = i;
            for(int j = 0 ; j < bit ; j++){
                if(nums[i] & (1<<j)) nearest_setbit[j] = i;
                else if(nearest_setbit[j] != n){
                    nearest = max(nearest , nearest_setbit[j]);
                }
            }
            ans[i] = nearest - i + 1;
        }

        return ans;


    }
};