#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        
        int n = nums.size();
        sort(nums.begin() , nums.end());
        vector<int> ans;

        for(int i = 1 ; i < n ; i++){
            if(nums[i] == nums[i-1]) ans.push_back(nums[i]);
        }

        return ans;


    }
};

int main() {
    
    return 0;
}