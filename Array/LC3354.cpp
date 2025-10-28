#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    bool right(vector<int> nums , int j){
        int n = nums.size();
        bool flag = true;

        while(j >= 0 && j < n){
            if(nums[j] == 0) {
                if(flag) j++;
                else j--;
            }
            else {
                nums[j] -= 1;
                if(flag){
                    flag = false;
                    j--;
                }
                else{
                    flag = true;
                    j++;
                }
            }

        }

        for(int i = 0 ; i < n ; i++) if(nums[i] != 0) return false;
        return true;

    }


    bool left(vector<int> nums , int j){
        int n = nums.size();
        bool flag = false;

        while(j >= 0 && j < n){
            if(nums[j] == 0) {
                if(flag) j++;
                else j--;
            }
            else {
                nums[j] -= 1;
                if(flag){
                    flag = false;
                    j--;
                }
                else{
                    flag = true;
                    j++;
                }
            }

        }

        for(int i = 0 ; i < n ; i++) if(nums[i] != 0) return false;
        return true;

    }

    int countValidSelections(vector<int>& nums) {
        
        int n = nums.size();
        vector<int> x(nums.begin() , nums.end());

        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] != 0) continue;
            if(right(x , i)) ans++;
            if(left(x , i)) ans++;

        }

        return ans;


    }
};

int main() {
    
    return 0;
}