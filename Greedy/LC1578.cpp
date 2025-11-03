#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        
        int n = neededTime.size();
        
        int i = 0 , j = 1;

        int ans = 0;

        while(j < n){

            int curr = neededTime[j];
            int prev = neededTime[i];

            if(colors[i] == colors[j]){
                
                if(prev < curr){
                    ans += prev;
                    i = j;
                }
                else{
                    ans += curr;
                }
                j++;

            }
            else{
                i = j;
                j++;
            }

        }


        return ans;

    }
};

int main() {
    
    return 0;
}