#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        
        int x = 0;

        for(string s : operations){
            if(s[1] == '+') x++;
            else x--;
        }

        return x;

    }
};

int main() {
    
    return 0;
}