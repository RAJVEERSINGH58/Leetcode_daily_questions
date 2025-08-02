#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    long long makeSimilar(vector<int>& nums, vector<int>& target) {

        int n = nums.size();

        sort(nums.begin() , nums.end());
        sort(target.begin() , target.end());

        vector<int> odd , oddTarget;
        vector<int> even , evenTarget;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] % 2 == 0) even.push_back(nums[i]);
            else odd.push_back(nums[i]);

            if(target[i] % 2 == 0) evenTarget.push_back(target[i]);
            else oddTarget.push_back(target[i]);
        }

        long long int cnt = 0;

        for(int i = 0 ; i < even.size() ; i++){
            cnt += (abs((long long)even[i] - (long long)evenTarget[i])) / 2;
        }

        for(int i = 0 ; i < odd.size() ; i++){
            cnt += (abs((long long)odd[i] - (long long)oddTarget[i])) / 2;
        }

        return cnt / 2;
        
    }
};

int main() {
    
    return 0;
}