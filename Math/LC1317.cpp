#include<bits/stdc++.h>
#include<vector>

using namespace std;

class Solution {
public:
    vector<int> getNoZeroIntegers(int n) {
        
        int a = 1 , b = n - 1;

        for(int i = 1 ; i < n ; i++){
            a = i;
            b = n - i;

            string s1 = to_string(a);
            string s2 = to_string(b);

            int count1 = count(s1.begin(), s1.end(), '0');
            int count2 = count(s2.begin(), s2.end(), '0');

            if(count1 == 0 && count2 == 0) return {a , b};

        }

        return {-1 , -1};

    }
};

int main() {
    
    return 0;
}