#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:

    bool validTraingle(int a , int b , int c){
        return a + b > c && b + c > a && a + c > b;
    }

    int search(int i , int j , vector<int>& nums){
        int n = nums.size();
        int lo = j + 1;
        int hi = n - 1;

        int x = nums[i] + nums[j];

        int mid;

        while(lo <= hi){
            mid = lo + (hi - lo) / 2;

            if(nums[mid] < x) lo = mid + 1;
            else hi = mid - 1;

        }

        return max(0 , hi - j);

    }

    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();

        int ans = 0;

        sort(nums.begin() , nums.end());

        for(int i = 0 ; i < n - 2 ; i++){
            for(int j = i + 1 ; j < n - 1 ; j++){
                int a = search(i , j , nums);
                ans += a;
            }
        }

        return ans;

    }
};

class Solution {
public:

    int triangleNumber(vector<int>& nums) {
        
        int n = nums.size();

        int ans = 0;

        sort(nums.begin() , nums.end());

        for(int i = n - 1 ; i >= 0; i--){
            int left = 0;
            int right = i - 1;

            while(left < right){
                if(nums[left] + nums[right] > nums[i]){
                    ans += right - left;
                    right--;
                }
                else{
                    left++;
                }
            }

        }

        return ans;

    }
};


int main() {
    
    return 0;
}