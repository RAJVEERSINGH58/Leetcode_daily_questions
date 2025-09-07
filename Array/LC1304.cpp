#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> sumZero(int n) {

        vector<int> ans;

        int x = n;

        for(int i = 0 ; i < n / 2 ; i++){
            ans.push_back(x);
            ans.push_back(-x);
            x--;
        }

        if(ans.size() < n) ans.push_back(0);

        return ans;
        
    }
};

int main() {
    
    return 0;
}