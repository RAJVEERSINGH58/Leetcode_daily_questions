#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2, int k) {
        if(k == 0){
            if(nums1 == nums2) return 0;
            else return -1;
        }

        long long posDiff = 0;
        long long negDiff = 0;

        for(int i = 0 ; i < nums1.size() ; i++){
            if((abs(nums1[i] - nums2[i]) % k) != 0) return -1;
            else if(nums1[i] > nums2[i]) posDiff += nums1[i] - nums2[i];
            else negDiff += nums2[i] - nums1[i];
        }

        if(posDiff == negDiff){
            return abs(posDiff) / k;
        }
        return -1;

    }
};

int main() {
    
    return 0;
}