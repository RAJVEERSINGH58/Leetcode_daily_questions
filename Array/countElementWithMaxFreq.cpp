#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int , int> mp;
        int max_freq = INT_MIN;
        for(int num : nums){
            mp[num]++;
            max_freq = max(max_freq , mp[num]);
        }

        int ans = 0;

        for(int x : nums){
            if(mp[x] == max_freq) ans++;
        }

        return ans;
    }
};

int main() {
    
    return 0;
}