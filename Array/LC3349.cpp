#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        
        int n = nums.size();

        if (k == 0) return true;
        if (k > n) return false;

        for(int i = 0 ; i <= n - 2 * k ; i++){

            int j;
            bool x = true;

            for(j = i + 1 ; j < i + k && j < n ; j++){
                if(nums[j-1] >= nums[j]){
                    x = false;
                    break;
                }
            }

            if(x == false) continue;

            for(int l = j + 1 ; l < j + k && l < n ; l++){
                if(nums[l-1] >= nums[l]) {
                    x = false;
                    break;
                }
            }

            if(x == false) continue;

            return true;

        }

        return false;

    }
};

int main() {
    
    return 0;
}