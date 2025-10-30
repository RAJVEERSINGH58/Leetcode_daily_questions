#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int minNumberOperations(vector<int>& target) {
        
        int n = target.size();
        vector<int> nums(n , 0);

        int prev = 0;
        int op = 0;

        for(int i = 0 ; i < n ; i++){

            int curr = target[i];

            if(prev >= curr){
                prev = curr;
                continue;
            }
            if(prev < curr){
                op += (curr - prev);
            }
            prev = curr;

        }

        return op;

    }
};

int main() {
    
    return 0;
}