#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i = 0 , j = n - 1;
        int ans = 0;
        while(i <= j){
            int currWater = min(height[i] , height[j]) * (j - i);
            ans = max(ans , currWater);
            if(height[i] < height[j]) i++;
            else j--;
        }
        return ans;
    }
};

int main() {
    
    return 0;
}